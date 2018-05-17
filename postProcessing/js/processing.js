let currentYear = new Date().getFullYear();
let data = {
    categories: [],
    entries: [],
    display: {
        columns: []
    },
    intervalDataFormat: "%Y",
    startDate: "" + currentYear -1 + "-01-01",
    endDate: "" + currentYear + "-12-31",
};
let formatDate = d3.timeFormat("%d-%b-%y");

d3.queue()
.defer(d3.csv, "/output/categories.csv")
.defer(d3.csv, "/output/bankAccountEntries.csv")
.await(setup);

function setup(error, categories, bankAccountEntries) {
    if(error) { console.log(error); }

    data.categories = categories;
    data.entries = bankAccountEntries;
    addCategoriesToForm(categories);
}

function addCategoriesToForm(categories) {
    let categoryInput = document.getElementById('category');
    for(let category of categories) {
        let option = document.createElement('option');
        option.value = category['name'];
        option.text = category['name'];
        categoryInput.add(option, null);
    }
}

function draw() {
    let chart = bb.generate({
        bindto: "#chart",
        axis: {
            x: {
                type: "timeseries",
                tick: {
                    format: data.intervalDateFormat
                  }
            }
        },
        data: {
            type: "bar",
            x: "dates",
            columns: data.display.columns,
            onclick: clickedBar,
        },
        zoom: {
            enabled: true
        }
    });
}

function clickedBar(data_clicked, element_clicked) {
    let category = data_clicked.name;
    let selected_interval = $('#interval').val();
    let start_date = new Date(data_clicked.x);
    let end_date = selected_interval === "year"
        ? new Date(start_date.getFullYear() + 1, start_date.getMonth(), start_date.getDate())
        : new Date(start_date.getFullYear(), start_date.getMonth() + 1, start_date.getDate());

    let category_data = getEntriesByCategory(category)
        .filter((entry) => {
            let entry_date = new Date(entry.year, entry.month, entry.day);
            return entry_date >= start_date && entry_date <= end_date;
        })
        .map((entry) => {
            return "<tr><th scope='row'>" + entry.id + "</th>" +
                    "<td>" + entry.account_from + "</td>" +
                    "<td>" + entry.account_to + "</td>" +
                    "<td>" + entry.description + "</td>" +
                    `<td>${entry.day}-${entry.month}-${entry.year}</td>` +
                    "<td>" + entry.name + "</td>" +
                    "<td>&euro;" + entry.amount + "</td>" +
                    "<td>" + entry.category + "</td>" +
                    "<td>" + entry.category2 + "</td><tr>";
        });

    let table_header = "<tr><th scope='col'>#</th>" +
        "<th scope='col'>Van account</th>" +
        "<th scope='col'>Naar account</th>" +
        "<th scope='col'>Omschrijving</th>" +
        "<th scope='col'>Datum</th>" +
        "<th scope='col'>Naam</th>" +
        "<th scope='col'>Bedrag</th>" +
        "<th scope='col'>Categorie</th>" +
        "<th scope='col'>Categorie 2</th>";

    let modal = $('#detailsModal');
    modal.find('.modal-body').html("<table class='table'><thead>" + table_header + "</thead><tbody>" + category_data.join('') + "</tbody></table>");
    modal.modal('show');
}

function prepareData(categories, interval) {
    let dataPerCategory = {};
    intervals = [];
    categories.forEach(categoryName => {
        entries = getEntriesByCategory(categoryName);

        // for each Entry in categoryName, add data
        entryDataPerInterval = {};
        entries.forEach(entry => {
            let dataEntry = data.entries
            let intervalTick = getIntervalTickFromDate(interval, entry.year, entry.month, entry.day);
            let intervalDate = Date.parse(intervalTick);
            if(!dateInRange(intervalDate, Date.parse(data.startDate), Date.parse(data.endDate))) {
                return;
            }
            if(!entryDataPerInterval.hasOwnProperty(intervalTick)) {
                entryDataPerInterval[intervalTick] = 0;
                if(!intervals.includes(intervalTick)) {
                    intervals.push(intervalTick);
                }
            }
            entryDataPerInterval[intervalTick] += parseFloat(entry.amount);
        });
        dataPerCategory[categoryName] = entryDataPerInterval;
    });

    intervals.sort();
    data.display.columns = [
        ["dates"].concat(intervals)
    ];

    for(let category in dataPerCategory) {
        categoryData = [category];
        intervals.forEach(interval => {
            if(dataPerCategory[category].hasOwnProperty(interval)) {
                categoryData.push(Number.parseFloat(dataPerCategory[category][interval]).toFixed(2));
            } else {
                categoryData.push(0);
            }
        });
        data.display.columns.push(categoryData);
    }
}

function dateInRange(date, startDate, endDate) {
    return date >= startDate && date <= endDate;
}

function getIntervalTickFromDate(interval, year, month, day) {
    let result = '';

    switch(interval) {
        case 'month':
            data.intervalDateFormat = "%B %Y";
            let monthStr = ("0" + month).slice(-2);
            result = year + '-' + monthStr + '-01';
            break;

        default:
        case 'year':
            data.intervalDateFormat = "%Y";
            result = year + '-01-01';
            break;
    }
    return result;
}

function getEntriesByCategory(categoryName) {
    let entryIDs = [];
    let entries = {};

    data.categories.forEach(category => {
        if(category.name == categoryName) {
            entryIDs = category.entries.split(';');
        }
    });

    // deduplicate entries
    entries = data.entries.filter(entry => {
        return entryIDs.includes(entry.id);
    });
    return entries;
}

$(document).ready(function() {
    $("#start_date").val(data.startDate);
    $("#end_date").val(data.endDate);

    $(document).on('click', '#go_button', function () {
        let selectedCategories = $('#category').val();
        let interval = $('#interval').val();

        if(selectedCategories.length === 0) {
            alert("Kies een categorie, anders doet 'ie het nie!");
            return;
        }
        prepareData(selectedCategories, interval);
        draw();
    });

    $(document).on('change', '#start_date', (element) => {
        data.startDate = element.currentTarget.value;
    });

    $(document).on('change', '#end_date', (element) => {
        data.endDate = element.currentTarget.value;
    });
});

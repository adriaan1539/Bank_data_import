let data = {
    categories: [],
    entries: [],
    display: {
        columns: []
    },
    intervalDataFormat: "%Y"
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
            columns: data.display.columns
        },
        zoom: {
            enabled: true
        }
    });
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

    entries = data.entries.filter(entry => {
        return entryIDs.includes(entry.id);
    });
    return entries;
}

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

$(document).ready(function() {

});

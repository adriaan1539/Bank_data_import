var data = {
    categories: [],
    entries: [],
    display: {
        columns: []
    }
};
var formatDate = d3.timeFormat("%d-%b-%y");

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
    var categoryInput = document.getElementById('category');
    for(var category of categories) {
        var option = document.createElement('option');
        option.value = category['Name'];
        option.text = category['Name'];
        categoryInput.add(option, null);
    }
}

function draw() {
    var chart = bb.generate({
        bindto: "#chart",
        axis: {
            x: {
                type: "timeseries",
                tick: {
                    format: "%Y-%m-%d"
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
    console.log("Data: ", categories, interval);

    data.display.columns = [
        ["dates", "2018-01-01", "2018-01-04", "2018-01-08"],
        ["cookie", 30, 200, 100],
        ["dookie", 130, 100, 140]
    ];
}

$('#go_button').on('click', function () {
    var selectedCategories = $('#category').val();
    var interval = $('#interval').val();

    if(selectedCategories.length === 0) {
        alert("Kies een categorie, anders doet 'ie het nie!");
        return;
    }
    prepareData(selectedCategories, interval);
    draw();
});

$(document).ready(function() {
    $('#category').multiselect();
});

from BankAccountEntry import BankAccountEntry
from Category import Category
from matplotlib2tikz import save as tikz_save
from collections import defaultdict

import csv
import datetime
import matplotlib.pyplot as plt

from PlotForm import PlotForm
from PyQt5 import QtCore, QtGui, QtWidgets
import sys


def plot(ui, setOfCategories, year):
    # Plot.
    x = []
    xTicks = []
    y = []
    for iCategory in range(len(setOfCategories)):
        category = setOfCategories[iCategory]
        x.append(iCategory)
        xTicks.append(category.GetName())
        y.append(category.GetAmount())
        ui.plot(x, y, xTicks)

years = dict()
setOfCategoriesPerYear = defaultdict(list)
setOfBankAccountEntries = []
# Import bank account entries from external csv file.
with open('output/bankAccountEntries.csv', newline='') as cSVFile:
    setOfBankAccountEntriesList = csv.reader(cSVFile, delimiter=',')
    for row in setOfBankAccountEntriesList:
        bankAccountEntry = BankAccountEntry(*row[1:14])
        setOfBankAccountEntries.append(bankAccountEntry)

# import pdb
# pdb.set_trace()

# Import categories from external csv file.
with open('output/categories.csv', newline='') as cSVFile:
    setOfCategoriesList = csv.reader(cSVFile, delimiter=',')

    for row in setOfCategoriesList:
        categoryName = row[0]
        bankAccountEntryIndices = [int(i) for i in row[1].split(';')]
        categoryAmountPerYear = defaultdict(int)
        for iBankAccountEntry in bankAccountEntryIndices:
            bankAccountEntry = setOfBankAccountEntries[iBankAccountEntry]
            year = bankAccountEntry.GetYear()
            years[year] = 1
            categoryAmountPerYear[year] += bankAccountEntry.GetAmount()
            categoryAmountPerYear[0] += bankAccountEntry.GetAmount()

        for year in categoryAmountPerYear:
            category = Category(categoryName,
                                bankAccountEntryIndices,
                                categoryAmountPerYear[year])
            setOfCategoriesPerYear[year].append(category)

app = QtWidgets.QApplication(sys.argv)
Form = QtWidgets.QWidget()
ui = PlotForm()
ui.setupUi(Form)

plot(ui, setOfCategoriesPerYear[0], "")

def year_changed(self):
    year = ui.yearCombo.currentText()
    print("Year changed to " + year)
    if year == "All":
        year = 0
    else:
        year = int(year)
    plot(ui, setOfCategoriesPerYear[year], "")

ui.yearCombo.currentIndexChanged.connect(year_changed)

ui.yearCombo.addItem("All", 0)
for year in sorted(years):
    ui.yearCombo.addItem(str(year), year)

# show the form
Form.show()
sys.exit(app.exec_())

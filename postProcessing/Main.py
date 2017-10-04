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
import time


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

# Extract the balance data from te bank account entries.
yearMonthDaySerialDateNumberBalance = []
serialDateNumber = 0
for bankAccountEntry in setOfBankAccountEntries:
    year = bankAccountEntry.GetYear()
    month = bankAccountEntry.GetMonth()
    day = bankAccountEntry.GetDay()
    dt = datetime.datetime(year=year, month=month, day=day)
    serialDateNumberOld = serialDateNumber
    serialDateNumber = time.mktime(dt.timetuple())
    if serialDateNumber == serialDateNumberOld:
        balance = balance + bankAccountEntry.GetBalance()
    else:
        balance = bankAccountEntry.GetBalance()
    yearMonthDaySerialDateNumberBalance.append([year,
                                                bankAccountEntry.GetMonth(),
                                                bankAccountEntry.GetDay(),
                                                serialDateNumber,
                                                bankAccountEntry.GetBalance()])

# Depict the balance as a function of time.
x = [yearMonthDaySerialDateNumberBalance[i][3] for i in range(len(yearMonthDaySerialDateNumberBalance))]
y = [yearMonthDaySerialDateNumberBalance[i][4] for i in range(len(yearMonthDaySerialDateNumberBalance))]

# Construction of the tick labels.
yearFirst = yearMonthDaySerialDateNumberBalance[0][0]
monthFirst = yearMonthDaySerialDateNumberBalance[0][1]
yearLast = yearMonthDaySerialDateNumberBalance[-1][0]
monthLast = yearMonthDaySerialDateNumberBalance[-1][1]
xTicks = []
xTicksLabels = []
for year in [yearFirst]:
    for month in range(monthFirst, 12 + 1):
        day = 1
        dt = datetime.datetime(year=year, month=month, day=day)
        serialDateNumber = time.mktime(dt.timetuple())
        xTicks.append(serialDateNumber)
        xTicksLabels.append(str(year) + "-" + str(month) + "-" + str(day))
for year in range(yearFirst + 1, yearLast):
    for month in range(1, 12 + 1):
        day = 1
        dt = datetime.datetime(year=year, month=month, day=day)
        serialDateNumber = time.mktime(dt.timetuple())
        xTicks.append(serialDateNumber)
        xTicksLabels.append(str(year) + "-" + str(month) + "-" + str(day))
for year in [yearLast]:
    for month in range(1, monthLast + 1):
        day = 1
        dt = datetime.datetime(year=year, month=month, day=day)
        serialDateNumber = time.mktime(dt.timetuple())
        xTicks.append(serialDateNumber)
        xTicksLabels.append(str(year) + "-" + str(month) + "-" + str(day))

# Plot the data and the labels.
plt.plot(x, y)
plt.xlabel('serial date number')
plt.xticks(xTicks, xTicksLabels, rotation=45, ha='right')
plt.ylabel('balance in [euro]')
plt.tight_layout()
plt.show()

# Construct the GUI.
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

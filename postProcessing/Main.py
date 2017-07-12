from BankAccountEntry import BankAccountEntry
from Category import Category
from matplotlib2tikz import save as tikz_save

import csv
import datetime
import matplotlib.pyplot as plt

from PlotForm import PlotForm
from PyQt5 import QtCore, QtGui, QtWidgets

# Import bank account entries from external csv file.
with open('output/bankAccountEntries.csv', newline='') as cSVFile:
    setOfBankAccountEntriesList = csv.reader(cSVFile, delimiter=',')
    setOfBankAccountEntries = []
    for row in setOfBankAccountEntriesList:
        bankAccountEntry = BankAccountEntry(*row[1:13])
        setOfBankAccountEntries.append(bankAccountEntry)

# Import categories from external csv file.
with open('output/categories.csv', newline='') as cSVFile:
    setOfCategoriesList = csv.reader(cSVFile, delimiter=',')
    setOfCategories = []
    for row in setOfCategoriesList:
        categoryName = row[0]
        bankAccountEntryIndices = [int(i) for i in row[1].split(';')]
        categoryAmount = 0
        for iBankAccountEntry in bankAccountEntryIndices:
            bankAccountEntry = setOfBankAccountEntries[iBankAccountEntry]
            categoryAmount = categoryAmount + bankAccountEntry.GetAmount()
        category = Category(categoryName,
                            bankAccountEntryIndices,
                            categoryAmount)
        setOfCategories.append(category)

# Plot.
x = []
xTicks = []
y = []
for iCategory in range(len(setOfCategories)):
    category = setOfCategories[iCategory]
    x.append(iCategory)
    xTicks.append(category.GetName())
    y.append(category.GetAmount())

print(x)
print(xTicks)
print(y)

# Bar plot of categories vs amounts.
fig, ax = plt.subplots()
plt.bar(x, y)
plt.xticks(x, xTicks, rotation=70, ha='right')
plt.xlabel("category")
plt.ylabel("expense")
plt.tight_layout()
ax.grid(b=True)
plt.show()
fig.savefig("category_vs_amount.eps")
#tikz_save("category_vs_amount.tikz")
#

import sys
app = QtWidgets.QApplication(sys.argv)
Form = QtWidgets.QWidget()
ui = PlotForm()
ui.setupUi(Form)

def button_pressed(self):
    print("Button pressed")
ui.pushButton.clicked.connect(button_pressed)

def year_changed(self):
    print("Year changed")

ui.yearCombo.currentIndexChanged.connect(year_changed)

# add today - 10 years => current year to 'yearCombo'
now = datetime.datetime.now()
for x in range(now.year - 10, now.year + 1):
    ui.yearCombo.addItem(str(x), x)

# show the form
Form.show()
sys.exit(app.exec_())

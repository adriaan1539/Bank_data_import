from BankAccountEntry import BankAccountEntry
from Category import Category
from matplotlib2tikz import save as tikz_save

import csv
import matplotlib.pyplot as plt

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
        for iBankAccountEntry in range(len(setOfBankAccountEntries)):
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

# Bar plot of categories vs amounts.
fig, ax = plt.subplots()
plt.bar(x, y)
plt.xticks(x, xTicks, rotation=70)
plt.xlabel("category")
plt.ylabel("expense")
plt.tight_layout()
fig.savefig("category_vs_amount.eps")
#tikz_save("category_vs_amount.tikz")

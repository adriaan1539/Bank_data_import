from BankAccountEntry import BankAccountEntry
from Category import Category
from matplotlib2tikz import save as tikz_save

import csv
import matplotlib.pyplot as plt

# Import bank account entries from external csv file.
with open('setOfBankAccountEntries.csv', newline='') as cSVFile:
    setOfBankAccountEntriesList = csv.reader(cSVFile, delimiter=',')
    setOfBankAccountEntries = []
    for row in setOfBankAccountEntriesList:
        bankAccountEntry = BankAccountEntry(*row)
        setOfBankAccountEntries.append(bankAccountEntry)

# Import categories from external csv file.
with open('setOfCategories.csv', newline='') as cSVFile:
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

# Histogram of categories vs amounts.
# x = numpy.array(numberOfStepsBatch).astype(numpy.int)
fig, ax = plt.subplots()
# ax.hist(x, normed=False)
# ax.hist(x,
plt.bar(x, y)
#         bins=numpy.arange(min(x)[0]-0.5,max(x)[0]+1+0.5,1),
#         normed=1,
#         edgecolor='black')
plt.xticks(x, xTicks, rotation=70)
plt.xlabel("category")
plt.ylabel("expense")
# fig.set_size_inches(2*16/2.54,2*9/2.54)
# plt.show()
# plt.gcf().subplots_adjust(bottom=0.25)
plt.tight_layout()
fig.savefig("category_vs_amount.eps")
# tikz_save("category_vs_amount.tikz")

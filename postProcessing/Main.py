import csv
from BankAccountEntry import BankAccountEntry
from Category import Category

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

# Plot
# for iCategory in range(len(setOfCategories)):

# Histogram of categories vs amounts.
# x = numpy.array(numberOfStepsBatch).astype(numpy.int)
# fig,ax=plt.subplots()
# ax.hist(x,
#         bins=numpy.arange(min(x)[0]-0.5,max(x)[0]+1+0.5,1),
#         normed=1,
#         edgecolor='black')
# ax.set_xticks(range(min(x)[0],max(x)[0]+1))
# plt.xticks(rotation=70)
# plt.title("Normalized distribution of the number of necessary steps in the pick and sort process")
# plt.xlabel("number of steps")
# plt.ylabel("normalized share in distribution")
# ax.text(1,
#         1,
#         "$N_{batch}=$"+str(x.size)+
#         "\n$N_{kits}=$"+str(int(numberOfKitsBatch[0][0]))+
#         "\n$N_{plies}=$"+str(int(numberOfPliesBatch[0][0]))+
#         "\n$N_{plies\_in\_kit\_lower\_bound}=$"+str(int(numberOfPliesInKitLowerBoundBatch[0][0]))+
#         "\n$N_{plies\_in\_kit\_upper\_bound}=$"+str(int(numberOfPliesInKitUpperBoundBatch[0][0]))+
#         "\n$\mu=$"+str('{0:.2f}'.format(numpy.mean(x)))+"="+str('{0:.2f}'.format(numpy.mean(x)/int(numberOfPliesBatch[0][0])))+"$\cdot N_{plies}$"+
#         "\n$\sigma=$"+str('{0:.2f}'.format(numpy.std(x)))+"="+str('{0:.2f}'.format(numpy.std(x)/int(numberOfPliesBatch[0][0])))+"$\cdot N_{plies}$"+
#         "\n$m=$"+str('{0:.2f}'.format(numpy.median(x)))+"="+str('{0:.2f}'.format(numpy.median(x)/int(numberOfPliesBatch[0][0])))+"$\cdot N_{plies}$",
#         verticalalignment='top',
#         horizontalalignment='right',
#         multialignment='right',
#         transform=ax.transAxes)
# fig.set_size_inches(2*16/2.54,2*9/2.54)
#plt.show()
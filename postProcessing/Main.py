import csv
from BankAccountEntry import BankAccountEntry

with open('setOfCategories.csv',newline='') as cSVFile:
    setOfCategoriesList=csv.reader(cSVFile,delimiter=',')
    setOfCategories=[]
    for row in setOfCategoriesList:
        category=Category(*row)
        setOfCategories.append(category)

with open('setOfBankAccountEntries.csv',newline='') as cSVFile:
    setOfBankAccountEntriesList=csv.reader(cSVFile,delimiter=',')
    setOfBankAccountEntries=[]
    for row in setOfBankAccountEntriesList:
        bankAccountEntry=BankAccountEntry(*row)
        setOfBankAccountEntries.append(bankAccountEntry)


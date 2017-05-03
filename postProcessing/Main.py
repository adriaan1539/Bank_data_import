print ("Hello World!")

import csv

class Complex:
    def __init__(self, realpart, imagpart):
        self.r = realpart
        self.i = imagpart

x = Complex(3.0,-4.5)
print(x.r)
print(x.i)

class BankAccountEntry:
    def __init__(self,
                 category,
                 amount,
                 rule,
                 nameOrDescription,
                 accountNumberConsidered,
                 accountNumberContra,
                 code,
                 sortOfMutation,
                 note,
                 day,
                 month,
                 year):
        self.category=category

with open('eggs.csv',newline='') as cSVFile:
    spamreader = csv.reader(cSVFile, delimiter=',')
    for row in spamreader:
        print(', '.join(row))

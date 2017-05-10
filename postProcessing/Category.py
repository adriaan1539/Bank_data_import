class Category:
    def __init__(self,
                 name,
                 bankAccountEntryIndices,
                 amount):
        self.name = name
        self.bankAccountEntryIndices = bankAccountEntryIndices
        self.amount = amount

    def GetBankAccountEntryIndices(self):
        return self.bankAccountEntryIndices

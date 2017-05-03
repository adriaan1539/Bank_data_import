class Category:
    def __init__(self,
                 category,
                 bankAccountEntryIndices):
        self.category=category
        self.bankAccountEntryIndices=bankAccountEntryIndices

    def GetBankAccountEntryIndices(self):
        return self.bankAccountEntryIndices
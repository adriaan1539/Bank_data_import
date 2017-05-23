class Category:
    def __init__(self,
                 name,
                 bankAccountEntryIndices,
                 amount):
        self.__amount = amount
        self.__bankAccountEntryIndices = bankAccountEntryIndices
        self.__name = name

    def GetAmount(self):
        return self.__amount

    def GetBankAccountEntryIndices(self):
        return self.__bankAccountEntryIndices

    def GetName(self):
        return self.__name
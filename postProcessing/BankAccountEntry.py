class BankAccountEntry:
    def __init__(self,
                 year,
                 month,
                 day,
                 nameOrDescription,
                 accountNumberConsidered,
                 accountNumberContra,
                 code,
                 amount,
                 sortOfMutation,
                 note,
                 category,
                 rule):
        self.__year = int(year)
        self.__month = int(month)
        self.__day = int(day)
        self.__nameOrDescription = nameOrDescription
        self.__accountNumberConsidered = accountNumberConsidered
        self.__accountNumberContra = accountNumberContra
        self.__code = code
        self.__amount = float(amount)
        self.__sortOfMutation = sortOfMutation
        self.__note = note
        self.__category = category
        self.__rule = rule

    def GetAmount(self):
        return self.__amount

    def GetDay(self):
        return self.__day

    def GetMonth(self):
        return self.__month

    def GetYear(self):
        return self.__year

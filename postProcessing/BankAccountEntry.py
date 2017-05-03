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
        self.year = year
        self.month = month
        self.day = day
        self.nameOrDescription = nameOrDescription
        self.accountNumberConsidered = accountNumberConsidered
        self.accountNumberContra = accountNumberContra
        self.code = code
        self.amount = amount
        self.sortOfMutation = sortOfMutation
        self.note=note
        self.category=category
        self.rule=rule
    def GetAmount(self):
        return self.amount
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
        self.year = int(year)
        self.month = int(month)
        self.day = int(day)
        self.nameOrDescription = nameOrDescription
        self.accountNumberConsidered = accountNumberConsidered
        self.accountNumberContra = accountNumberContra
        self.code = code
        self.amount = float(amount)
        self.sortOfMutation = sortOfMutation
        self.note = note
        self.category = category
        self.rule = rule

    def GetAmount(self):
        return self.amount

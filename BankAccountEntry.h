#ifndef BANKACCOUNTENTRY_H
#define BANKACCOUNTENTRY_H

#include <string>

class BankAccountEntry
{
	private:
		double 			amount;
		std::string 	nameOrDescription;
		std::string 	accountNumberConsidered;
		std::string 	accountNumberContra;
		std::string 	code;
		std::string 	sortOfMutation;
		std::string 	note;
		unsigned int 	day;
		unsigned int 	iCategory;
		unsigned int 	iRule;
		unsigned int 	month;
		unsigned int 	year;
	protected:
	public:
		BankAccountEntry();
		BankAccountEntry(	unsigned int year,
							unsigned int month,
							unsigned int day,
							std::string nameOrDescription,
							std::string accountNumberConsidered,
							std::string accountNumberContra,
							std::string code,
							double amount,
							std::string sortOfMutation,
							std::string note);

		double 			GetAmount(void);
		std::string 	GetNameOrDescription(void);
		unsigned int 	GetDay(void);
		unsigned int 	GetMonth(void);
		unsigned int 	GetYear(void);
		void 			printToConsole(void);
		void 			printToFile(std::string);
		void 			setIndexCategoryAndRule(	unsigned int iCategory,
													unsigned int iRule);

};
#endif

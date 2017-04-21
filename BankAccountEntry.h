#ifndef BANKACCOUNTENTRY_H
#define BANKACCOUNTENTRY_H

#include "Category.h"
#include "Rule.h"
#include <string>

class Category; // Forward declaration.
class Rule; // Forward declaration.

class BankAccountEntry
{
	private:
		Category*		category;
		double 			amount;
		Rule* 			rule;
		std::string 	nameOrDescription;
		std::string 	accountNumberConsidered;
		std::string 	accountNumberContra;
		std::string 	code;
		std::string 	sortOfMutation;
		std::string 	note;
		unsigned int 	day;
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
		std::string 	GetNote(void);
		std::string		ToCSV(void);
		unsigned int 	GetDay(void);
		unsigned int 	GetMonth(void);
		unsigned int 	GetYear(void);
		void 			PrintToConsole(void);
		void 			PrintToFile(std::string);
		void 			SetIndexCategoryAndRule(	Category* category,
													Rule* rule);
};
#endif

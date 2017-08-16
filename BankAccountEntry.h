#ifndef BANKACCOUNTENTRY_H
#define BANKACCOUNTENTRY_H

#include <string>
#include <vector>

class BankAccountEntry
{
private:
		double 						amount;
		int							balance;
		std::string 				nameOrDescription;
		std::string 				accountNumberConsidered;
		std::string 				accountNumberContra;
		std::string 				code;
		std::string 				sortOfMutation;
		std::string 				note;
		std::vector<std::string> 	categories;
		std::vector<std::string> 	rules;
		unsigned int 				day;
		unsigned int 				month;
		unsigned int 				year;
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

		double 						GetAmount(void);
		int							GetBalance(void);
		std::string					GetAccountNumberConsidered(void);
		std::string					GetAccountNumberContra(void);
		std::string					GetCategoryNames(void);
		std::string					GetCode(void);
		std::string 				GetNameOrDescription(void);
		std::string 				GetNote(void);
		std::string					GetRuleNames(void);
		std::string					GetSortOfMutation(void);
		std::string					ToCSV(int index);
		std::vector<std::string> 	GetCategories(void);
		unsigned int 				GetDay(void) const;
		unsigned int 				GetMonth(void) const;
		unsigned int 				GetYear(void) const;
		void 						AddCategoryAndRuleName(std::string category, std::string rule);
		void 						PrintToConsole(void);
		void 						PrintToFile(std::string);
		void						SetBalance(int);
};
#endif

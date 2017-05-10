#ifndef CATEGORY_H
#define CATEGORY_H

#include "BankAccountEntry.h"
#include "Rule.h"
#include <string>
#include <vector>

class BankAccountEntry; // Forward declaration.
class Rule; // Forward declaration.

class Category
{
	private:
		double							amountTotal=0.0;
		std::string 					name;
		std::vector<BankAccountEntry*> 	setOfBankAccountEntries;
		std::vector<Rule> 				setOfRules;
	protected:
	public:
		Category();
		Category(std::string nameCategory);
		
		void 							AddRule(Rule);
		double		 					GetAmountTotal();
		std::string 					GetName();
		int 							GetNumberOfRules();
		std::vector<BankAccountEntry*> 	GetSetOfBankAccountEntries();
		std::vector<Rule> 				GetSetOfRules();
		void 							PrintNameOfAllRules();
		void 							PrintSetOfBankAccountEntryIndices();
		void 							AddBankAccountEntry(BankAccountEntry*);
};
#endif

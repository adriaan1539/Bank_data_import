#ifndef CATEGORY_H
#define CATEGORY_H

#include "BankAccountEntry.h"
#include "Rule.h"
#include <string>
#include <vector>

class Category
{
	private:
		std::string name;
		std::vector<BankAccountEntry*> setOfBankAccountEntries;
		std::vector<Rule> setOfRules;
	protected:
	public:
		Category();
		Category(std::string nameCategory);
		
		void AddRule(Rule rule);
		std::string GetNameCategory();
		int GetNumberOfRules();
		std::vector<Rule> GetSetOfRules();
		void PrintNameOfAllRules();
		void PrintSetOfBankAccountEntryIndices();
		void SetBankAccountEntry(BankAccountEntry* bankAccountEntry);
};
#endif

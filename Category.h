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
		std::vector<int> setOfBankAccountEntryIndices;
		std::vector<Rule> setOfRules;
	protected:
	public:
		Category();
		Category(std::string nameCategory);
		
		void AddRule(Rule rule);
		std::string GetNameCategory();
		int GetNumberOfRules();
		void PrintNameOfAllRules();
		void PrintSetOfBankAccountEntryIndices();
		void SetIndexBankAccountEntry(unsigned int iBankAccountEntry);
};
#endif

#ifndef CATEGORY_H
#define CATEGORY_H

#include "BankAccountEntry.h"
#include <functional>
#include <string>
#include <vector>

class Rule; // Forward declaration. Necessary because class Rule is used in class Category.

class Category
{
	private:
		std::string nameCategory;
		std::vector<int> setOfBankAccountEntryIndices;
	protected:
	public:
		Category();
		Category(std::string nameCategory);
		
		std::string GetNameCategory();
		int GetNumberOfRules();
		void PrintNameOfAllRules();
		void PrintSetOfBankAccountEntryIndices();
		void SetIndexBankAccountEntry(unsigned int iBankAccountEntry);
		
		std::vector<Rule> setOfRules;
};

class Rule : public Category
{
	private:
		std::string nameRule;
	protected:
	public:
		Rule();
		Rule(std::function<bool(BankAccountEntry)> rule,std::string nameRule);
		std::function<bool(BankAccountEntry)> ruleFunction;
		std::string GetNameRule();
};
#endif

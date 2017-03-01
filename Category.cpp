#include "Category.h"
#include <iostream>
#include "Rule.h"

Category::Category()
{
}

Category::Category(std::string nameCategory)
{
	this->name=nameCategory;
}

void Category::AddRule(Rule rule)
{
	this->setOfRules.push_back(rule);
}

std::string Category::GetNameCategory()
{
	return name;
}

int Category::GetNumberOfRules()
{
	return setOfRules.size();
}

void Category::PrintNameOfAllRules()
{
	for (unsigned int iRule=0;iRule<setOfRules.size();iRule++)
	{
		std::cout<<setOfRules[iRule].GetNameRule()<<"\n";
	}
}

void Category::PrintSetOfBankAccountEntryIndices()
{
	for (unsigned int iSetOfBankAccountEntryIndices=0;iSetOfBankAccountEntryIndices<setOfBankAccountEntryIndices.size();iSetOfBankAccountEntryIndices++)
	{
		std::cout<<setOfBankAccountEntryIndices[iSetOfBankAccountEntryIndices]<<"\n";
	}
}

Rule::Rule()
{
}

Rule::Rule(	std::function<bool(BankAccountEntry)> rule,
			std::string nameRule)
{
	this->ruleFunction=rule;
	this->nameRule=nameRule;
}

std::string Rule::GetNameRule()
{
	return nameRule;
}

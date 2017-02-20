#include "Category.h"
#include <iostream>

Category::Category()
{
}

Category::Category(std::string nameCategory)
{
	this->nameCategory=nameCategory;
}

void Category::SetIndexBankAccountEntry(unsigned int iBankAccountEntry)
{
	setOfBankAccountEntryIndices.push_back(iBankAccountEntry);
}

std::string Category::GetNameCategory()
{
	return nameCategory;
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

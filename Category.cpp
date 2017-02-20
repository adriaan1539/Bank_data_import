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

Rule::Rule(std::function<bool(BankAccountEntry)> rule)
{
	this->ruleFunction=rule;
	setOfRules.push_back(*this);
}

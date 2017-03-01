#include "Category.h"
#include <iostream>
#include "Rule.h"
#include <string>

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

std::vector<Rule> Category::GetSetOfRules()
{
	return this->setOfRules;
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
	for (unsigned int iSetOfBankAccountEntryIndices=0;iSetOfBankAccountEntryIndices<setOfBankAccountEntries.size();iSetOfBankAccountEntryIndices++)
	{
		std::cout<<setOfBankAccountEntries[iSetOfBankAccountEntryIndices]<<"\n";
	}
}

void Category::SetBankAccountEntry(BankAccountEntry* bankAccountEntry)
{
	setOfBankAccountEntries.push_back(bankAccountEntry);
}

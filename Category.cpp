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

double Category::GetAmountTotal()
{
	return amountTotal;
}

std::string Category::GetName()
{
	return name;
}

int Category::GetNumberOfRules()
{
	return setOfRules.size();
}

std::vector<BankAccountEntry*> Category::GetSetOfBankAccountEntries()
{
	return this->setOfBankAccountEntries;
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

void Category::AddBankAccountEntry(BankAccountEntry* bankAccountEntry)
{
	setOfBankAccountEntries.push_back(bankAccountEntry);
	amountTotal=amountTotal+bankAccountEntry->GetAmount();
}

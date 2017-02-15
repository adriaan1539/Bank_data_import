#include "Category.h"

Category::Category()
{
}

Category::Category(std::string nameCategory)
{
	this->nameCategory=nameCategory;
}

void Category::SetIndexBankAccountEntry(unsigned int iBankAccountEntry)
{
	setOfIndices.push_back(iBankAccountEntry);
}

Rule::Rule()
{
}

Rule::Rule(std::function<bool(BankAccountEntry)> rule)
{
	setOfRules.push_back(rule);
}

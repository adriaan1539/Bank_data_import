#include "CategorizeBankAccountEntries.h"
#include <iostream>

void CategorizeBankAccountEntries(	std::vector<BankAccountEntry>& setOfBankAccountEntries,
									std::vector<Category>& setOfCategories)
{
	BankAccountEntry* bankAccountEntry;
	Category* category;
	std::vector<Rule> setOfRules;
	Rule rule;
	std::function<bool(BankAccountEntry)> ruleFunction;
	int numberOfSuccesfullyProcessed=0;
	int numberOfFailedToProcess=0;
	unsigned int iCategory=0;
	unsigned int iRule=0;

	for (unsigned int iBankAccountEntry=0;iBankAccountEntry<setOfBankAccountEntries.size();iBankAccountEntry++)
	{
		bankAccountEntry=&setOfBankAccountEntries[iBankAccountEntry];
		int matches = 0;

		iCategory=0; // Reset
		while (iCategory<setOfCategories.size())
		{
			category=&setOfCategories[iCategory];
			setOfRules=category->GetSetOfRules();
			iRule=0; // Reset
			while (iRule<setOfRules.size())
			{
				rule=setOfRules[iRule];
				ruleFunction=rule.ruleFunction;
				bool compliantWithRule = ruleFunction(*bankAccountEntry);
				if (compliantWithRule==true)
				{
					category->AddBankAccountEntry(bankAccountEntry);
					bankAccountEntry->AddCategoryAndRuleName(category->GetName(),rule.GetNameRule());
					matches++;
					break; // exit rule while loop
				}
				iRule++;
			}
			iCategory++;
		}

		if (matches > 0)
		{
			numberOfSuccesfullyProcessed++;
		}
		else
		{
			numberOfFailedToProcess++;
		}
	}
	std::cout<<"\rWe have "<<numberOfSuccesfullyProcessed<<" successes and "<<numberOfFailedToProcess<<" failures out of "<<setOfBankAccountEntries.size()<<".\n";
}

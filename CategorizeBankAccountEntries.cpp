#include "CategorizeBankAccountEntries.h"
#include <iostream>

void CategorizeBankAccountEntries(	std::vector<BankAccountEntry>& setOfBankAccountEntries,
									std::vector<Category>& setOfCategories)
{
	bool compliantWithRule;
	BankAccountEntry* bankAccountEntry;
	Category* category;
	std::vector<Rule> setOfRules;
	Rule rule;
	std::function<bool(BankAccountEntry)> ruleFunction;
	int numberOfSuccesfullyProcessed=0;
	int numberOfFailedToProcess=0;

	for (unsigned int iBankAccountEntry=0;iBankAccountEntry<setOfBankAccountEntries.size();iBankAccountEntry++)
	{
		std::cout<<"Processing bank entry "<<iBankAccountEntry<<" of "<<setOfBankAccountEntries.size()<<". ";

		compliantWithRule=false; // Reset per instance of BankAccountEntry.

		bankAccountEntry=&setOfBankAccountEntries[iBankAccountEntry];

		for (unsigned int iCategory=0;iCategory<setOfCategories.size();iCategory++)
		{
			category=&setOfCategories[iCategory];
			setOfRules=category->GetSetOfRules();
			for (unsigned int iRule=0;iRule<setOfRules.size();iRule++)
			{
				rule=setOfRules[iRule];
				ruleFunction=rule.ruleFunction;
				compliantWithRule=ruleFunction(*bankAccountEntry);
				if (compliantWithRule==true)
				{
					category->SetBankAccountEntry(bankAccountEntry);
				}
			}
		}

		if (compliantWithRule==true)
		{
			numberOfSuccesfullyProcessed++;
			std::cout<<"SUCCESS.\n";
		}
		else if (compliantWithRule==false)
		{
			numberOfFailedToProcess++;
			std::cout<<"FAILED.\n";
		}
	}

	std::cout<<"Processed "<<numberOfSuccesfullyProcessed<<" out of "<<setOfBankAccountEntries.size()<<" succesfully.\n";
	std::cout<<"Processing "<<numberOfFailedToProcess<<" out of "<<setOfBankAccountEntries.size()<<" failed.\n";
}

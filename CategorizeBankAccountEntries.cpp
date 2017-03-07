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
	unsigned int iCategory=0;
	unsigned int iRule=0;

	for (unsigned int iBankAccountEntry=0;iBankAccountEntry<setOfBankAccountEntries.size();iBankAccountEntry++)
	{
		std::cout<<"Processing bank entry "<<iBankAccountEntry<<" of "<<setOfBankAccountEntries.size()<<". ";

		compliantWithRule=false; // Reset per instance of BankAccountEntry.

		bankAccountEntry=&setOfBankAccountEntries[iBankAccountEntry];

		iCategory=0; // Reset
		while (compliantWithRule==false && iCategory<setOfCategories.size())
		{
			category=&setOfCategories[iCategory];
			setOfRules=category->GetSetOfRules();
			iRule=0; // Reset
			while (compliantWithRule==false && iRule<setOfRules.size())
			{
				rule=setOfRules[iRule];
				ruleFunction=rule.ruleFunction;
				compliantWithRule=ruleFunction(*bankAccountEntry);
				if (compliantWithRule==true)
				{
					category->SetBankAccountEntry(bankAccountEntry);
					bankAccountEntry->printToConsole();
				}
				iRule++;
			}
			iCategory++;
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

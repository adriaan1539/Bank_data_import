#include "CategorizeBankAccountEntriesByYear.h"

std::map<int,std::vector<int>> CategorizeBankAccountEntriesByYear(std::vector<BankAccountEntry>& setOfBankAccountEntries)
{
	std::map<int,std::vector<int>> yearToBankAccountEntryIndices;
	std::vector<int> bankAccountEntryIndices;
	for (int iBankAccountEntry = 0; iBankAccountEntry < setOfBankAccountEntries.size(); iBankAccountEntry++)
	{
		BankAccountEntry bankAccountEntry = setOfBankAccountEntries[iBankAccountEntry];
		int year = bankAccountEntry.GetYear();
		if ( yearToBankAccountEntryIndices.find(year) == yearToBankAccountEntryIndices.end() )
		{
			bankAccountEntryIndices = {iBankAccountEntry};
			yearToBankAccountEntryIndices.insert(std::pair<int, std::vector<int>>(year, bankAccountEntryIndices));
		}
		else
		{
			yearToBankAccountEntryIndices[year].push_back(iBankAccountEntry);
		}
	}

	return yearToBankAccountEntryIndices;
}

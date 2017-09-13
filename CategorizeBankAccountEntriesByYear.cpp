#include "CategorizeBankAccountEntriesByYear.h"

CategorizeBankAccountEntriesByYear(std::vector<BankAccountEntry>& setOfBankAccountEntries)
{
	std::map<int,std::vector<int>> yearToBankAccountEntryIndices;
	std::vector<int> bankAccountEntryIndices;
	for (unsigned int iBankAccountEntry = 0; iBankAccountEntry < setOfBankAccountEntries.size(); iBankAccountEntry++)
	{
		bankAccountEntry = &setOfBankAccountEntries[iBankAccountEntry];
		year = bankAccountEntry.GetYear();
		if ( yearToBankAccountEntryIndices.find(year) == yearToBankAccountEntryIndices.end() )
		{
			bankAccountEntryIndices = {iBankAccountEntry};
			yearToBankAccountEntryIndices.insert(year, bankAccountEntryIndices);
		}
		else
		{
			yearToBankAccountEntryIndices[year].push_back(iBankAccountEntry);
		}
	}

	return yearToBankAccountEntryIndices;
}

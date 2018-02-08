#include "CategorizeBankAccountEntriesDefault.h"

std::map<int,std::vector<int>> CategorizeBankAccountEntriesDefault(std::vector<BankAccountEntry>& setOfBankAccountEntries)
{
	std::map<int,std::vector<int>> dayToBankAccountEntryIndices;
	std::map<int,std::vector<int>> monthToBankAccountEntryIndices;
	std::map<int,std::vector<int>> yearToBankAccountEntryIndices;
	std::vector<int> bankAccountEntryIndices;
	for (int iBankAccountEntry = 0; iBankAccountEntry < setOfBankAccountEntries.size(); iBankAccountEntry++)
	{
		BankAccountEntry bankAccountEntry = setOfBankAccountEntries[iBankAccountEntry];

		// Fill dayToBankAccountEntryIndices.
		int day = bankAccountEntry.GetDay();
		if ( dayToBankAccountEntryIndices.find(day) == dayToBankAccountEntryIndices.end() )
		{
			bankAccountEntryIndices = {iBankAccountEntry};
			dayToBankAccountEntryIndices.insert(std::pair<int, std::vector<int>>(day, bankAccountEntryIndices));
		}
		else
		{
			dayToBankAccountEntryIndices[day].push_back(iBankAccountEntry);
		}

		// Fill monthToBankAccountEntryIndices.
		int month = bankAccountEntry.GetMonth();
		if ( monthToBankAccountEntryIndices.find(month) == monthToBankAccountEntryIndices.end() )
		{
			bankAccountEntryIndices = {iBankAccountEntry};
			monthToBankAccountEntryIndices.insert(std::pair<int, std::vector<int>>(month, bankAccountEntryIndices));
		}
		else
		{
			monthToBankAccountEntryIndices[month].push_back(iBankAccountEntry);
		}

		// Fill yearToBankAccountEntryIndices.
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

#include "CategorizeBankAccountEntriesDefault.h"
#include "DateToDayOfWeek.h"
#include <string>

auto CategorizeBankAccountEntriesDefault(std::vector<BankAccountEntry> setOfBankAccountEntries)
{
	// Declaration of maps corresponding to default properties which we will use for categorization.
	std::map<int,std::vector<int>> additionOrSubtractionToBankAccountEntryIndices;
	std::map<int,std::vector<int>> dayToBankAccountEntryIndices;
	std::map<std::string,std::vector<int>> dayOfTheWeekToBankAccountEntryIndices;
	std::map<int,std::vector<int>> monthToBankAccountEntryIndices;
	std::map<std::string,std::vector<int>> mutationToBankAccountEntryIndices;
	std::map<int,std::vector<int>> yearToBankAccountEntryIndices;

	// Define all the maps.
	std::vector<int> bankAccountEntryIndices;
	for ( int iBankAccountEntry = 0; iBankAccountEntry < int(setOfBankAccountEntries.size()); iBankAccountEntry++)
	{
		BankAccountEntry bankAccountEntry = setOfBankAccountEntries[iBankAccountEntry];

		// Define additionOrSubtractionToBankAccountEntryIndices.
		bool add = (bankAccountEntry.GetAmount() > 0 );
		if ( additionOrSubtractionToBankAccountEntryIndices.find(int(add)) == additionOrSubtractionToBankAccountEntryIndices.end() )
		{
			bankAccountEntryIndices = {iBankAccountEntry};
			additionOrSubtractionToBankAccountEntryIndices.insert(std::pair<int, std::vector<int>>(int(add), bankAccountEntryIndices));
		}
		else
		{
			additionOrSubtractionToBankAccountEntryIndices[int(add)].push_back(iBankAccountEntry);
		}

		// Define dayToBankAccountEntryIndices.
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

		// Define dayOfTheWeekToBankAccountEntryIndices.
		std::string dayOfTheWeek = DateToDayOfWeek(bankAccountEntry.GetDay(), bankAccountEntry.GetMonth(), bankAccountEntry.GetYear());
		if ( dayOfTheWeekToBankAccountEntryIndices.find(dayOfTheWeek) == dayOfTheWeekToBankAccountEntryIndices.end() )
		{
			bankAccountEntryIndices = {iBankAccountEntry};
			dayOfTheWeekToBankAccountEntryIndices.insert(std::pair<std::string, std::vector<int>>(dayOfTheWeek, bankAccountEntryIndices));
		}
		else
		{
			dayOfTheWeekToBankAccountEntryIndices[dayOfTheWeek].push_back(iBankAccountEntry);
		}

		// Define monthToBankAccountEntryIndices.
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

		// Define mutationToBankAccountEntryIndices.
		std::string mutation = bankAccountEntry.GetSortOfMutation();
		if ( mutationToBankAccountEntryIndices.find(mutation) == mutationToBankAccountEntryIndices.end() )
		{
			bankAccountEntryIndices = {iBankAccountEntry};
			mutationToBankAccountEntryIndices.insert(std::pair<std::string, std::vector<int>>(mutation, bankAccountEntryIndices));
		}
		else
		{
			mutationToBankAccountEntryIndices[mutation].push_back(iBankAccountEntry);
		}

		// Define yearToBankAccountEntryIndices.
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

	// Construct output argument.
	struct result
	{
		std::map<int,std::vector<int>> additionOrSubtractionToBankAccountEntryIndicesA;
		std::map<int,std::vector<int>> dayToBankAccountEntryIndicesA;
		std::map<std::string,std::vector<int>> dayOfTheWeekToBankAccountEntryIndicesA;
		std::map<int,std::vector<int>> monthToBankAccountEntryIndicesA;
		std::map<std::string,std::vector<int>> mutationToBankAccountEntryIndicesA;
		std::map<int,std::vector<int>> yearToBankAccountEntryIndicesA;
	};

	return result
	{
		additionOrSubtractionToBankAccountEntryIndices,
		dayToBankAccountEntryIndices,
		dayOfTheWeekToBankAccountEntryIndices,
		monthToBankAccountEntryIndices,
		mutationToBankAccountEntryIndices,
		yearToBankAccountEntryIndices
	};
}

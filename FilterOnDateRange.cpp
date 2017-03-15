#include "FilterOnDateRange.h"

void FilterOnDateRange(	std::vector<BankAccountEntry>& setOfBankAccountEntries,
						std::vector<int>& dateRange)
{
	unsigned int yearRangeStart=dateRange[0];
	unsigned int monthRangeStart=dateRange[1];
	unsigned int dayRangeStart=dateRange[2];
	unsigned int yearRangeEnd=dateRange[3];
	unsigned int monthRangeEnd=dateRange[4];
	unsigned int dayRangeEnd=dateRange[5];
	std::vector<BankAccountEntry*> setOfBankAccountEntriesRange;
	for (unsigned int iBankAccountEntry=0;iBankAccountEntry<setOfBankAccountEntries.size();iBankAccountEntry++)
	{
		BankAccountEntry* bankAccountEntry=&setOfBankAccountEntries[iBankAccountEntry];
		unsigned int year=bankAccountEntry->GetYear();
		unsigned int month=bankAccountEntry->GetMonth();
		unsigned int day=bankAccountEntry->GetDay();
		if (yearRangeStart<=year && year<=yearRangeEnd &&
			monthRangeStart<=month && month<=monthRangeEnd &&
			dayRangeStart<=day && day<=dayRangeEnd)
		{
			setOfBankAccountEntriesRange.push_back(bankAccountEntry);
		}
	}
}

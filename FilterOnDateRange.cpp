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
	unsigned int iBankAccountEntry=0;
	while (iBankAccountEntry<setOfBankAccountEntries.size())
	{
		BankAccountEntry* bankAccountEntry=&setOfBankAccountEntries[iBankAccountEntry];
		unsigned int year=bankAccountEntry->GetYear();
		unsigned int month=bankAccountEntry->GetMonth();
		unsigned int day=bankAccountEntry->GetDay();
		if (yearRangeStart<=year && year<=yearRangeEnd &&
			monthRangeStart<=month && month<=monthRangeEnd &&
			dayRangeStart<=day && day<=dayRangeEnd)
		{
			iBankAccountEntry++;
		}
		else
		{
			setOfBankAccountEntries.erase(setOfBankAccountEntries.begin()+iBankAccountEntry);
		}
	}
}

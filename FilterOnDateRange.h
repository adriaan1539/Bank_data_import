#ifndef FILTERONDATERANGE_H
#define FILTERONDATERANGE_H

#include "BankAccountEntry.h"
#include <vector>

void FilterOnDateRange(	std::vector<BankAccountEntry>& setOfBankAccountEntries,
						std::vector<int>& dateRange);

#endif



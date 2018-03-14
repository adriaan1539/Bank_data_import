#ifndef CATEGORIZEBANKACCOUNTENTRIESDEFAULT_H
#define CATEGORIZEBANKACCOUNTENTRIESDEFAULT_H

#include "BankAccountEntry.h"
#include <map>
#include <vector>

// Construct struct so that multiple output arguments can be returned by 'CategorizeBankAccountEntriesDefault'.
struct StructCategorizeBankAccountEntriesDefault
{
	std::map<int,std::vector<int>> additionOrSubtractionToBankAccountEntryIndicesTemp;
	std::map<int,std::vector<int>> dayToBankAccountEntryIndicesTemp;
	std::map<std::string,std::vector<int>> dayOfTheWeekToBankAccountEntryIndicesTemp;
	std::map<int,std::vector<int>> monthToBankAccountEntryIndicesTemp;
	std::map<std::string,std::vector<int>> mutationToBankAccountEntryIndicesTemp;
	std::map<int,std::vector<int>> yearToBankAccountEntryIndicesTemp;
};

StructCategorizeBankAccountEntriesDefault CategorizeBankAccountEntriesDefault(std::vector<BankAccountEntry>);

#endif

#ifndef CATEGORIZEBANKACCOUNTENTRIESDEFAULT_H
#define CATEGORIZEBANKACCOUNTENTRIESDEFAULT_H

#include "BankAccountEntry.h"
#include <map>
#include <vector>

std::map<int,std::vector<int>> CategorizeBankAccountEntriesDefault(std::vector<BankAccountEntry>&);

#endif

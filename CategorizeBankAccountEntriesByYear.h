#ifndef CATEGORIZEBANKACCOUNTENTRIESBYYEAR_H
#define CATEGORIZEBANKACCOUNTENTRIESBYYEAR_H

#include "BankAccountEntry.h"
#include <map>
#include <vector>

std::map<int,std::vector<int>> CategorizeBankAccountEntriesByYear(std::vector<BankAccountEntry>&);

#endif

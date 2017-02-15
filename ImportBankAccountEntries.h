#ifndef IMPORTBANKACCOUNTENTRIES_H
#define IMPORTBANKACCOUNTENTRIES_H

#include "BankAccountEntry.h"
#include <string>
#include <vector>

std::vector<BankAccountEntry> ImportBankAccountEntries(std::vector<std::string> listOfInputFiles);
#endif



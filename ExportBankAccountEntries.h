#ifndef EXPORTBANKACCOUNTENTRIES_H
#define EXPORTBANKACCOUNTENTRIES_H

#include "BankAccountEntry.h"
#include <string>
#include <vector>
#include <map>

std::map<std::string, std::vector<int>> ExportBankAccountEntries(	std::vector<BankAccountEntry>& setOfBankAccountEntries,
								std::string& fileName);
#endif



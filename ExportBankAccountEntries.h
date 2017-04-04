#ifndef EXPORTBANKACCOUNTENTRIES_H
#define EXPORTBANKACCOUNTENTRIES_H

#include "BankAccountEntry.h"
#include <string>
#include <vector>

void ExportBankAccountEntries(	std::vector<BankAccountEntry>& setOfBankAccountEntries,
								std::string& fileName);
#endif



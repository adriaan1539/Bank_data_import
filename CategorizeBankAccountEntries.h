#ifndef CATEGORIZEBANACCOUNTENTRIES_H
#define CATEGORIZEBANACCOUNTENTRIES_H

#include "BankAccountEntry.h"
#include "CategorizeBankAccountEntries.h"
#include "Category.h"
#include <vector>

void CategorizeBankAccountEntries(	std::vector<BankAccountEntry> setOfBankAccountEntries,
									std::vector<Category> setOfCategories);

#endif



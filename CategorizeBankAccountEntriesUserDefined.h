#ifndef CATEGORIZEBANACCOUNTENTRIESUSERDEFINED_H
#define CATEGORIZEBANACCOUNTENTRIESUSERDEFINED_H

#include "BankAccountEntry.h"
#include "CategorizeBankAccountEntriesUserDefined.h"
#include "Category.h"
#include <vector>

void CategorizeBankAccountEntriesUserDefined(	std::vector<BankAccountEntry>& setOfBankAccountEntries,
												std::vector<Category>& setOfCategories);

#endif



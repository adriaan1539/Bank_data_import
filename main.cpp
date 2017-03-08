#include "BankAccountEntry.h"
#include "BankAccountEntryFormat.h"
#include "BankAccountEntryParser.h"
#include "boost/filesystem/operations.hpp"
#include "boost/filesystem/path.hpp"
#include "boost/progress.hpp"
#include "CategorizeBankAccountEntries.h"
#include "Category.h"
#include <fstream>
#include "ImportBankAccountEntries.h"
#include "ImportCategories.h"
#include <iostream>
#include "ListOfFiles.h"
#include <regex>
#include <string>
#include "StringInName.h"
#include <vector>

int main (void)
{
	// List files we will import to extract data from. We should make this an input argument of the program later
	std::string dirInput="input";
	std::vector<std::string> listOfInputFiles=ListOfFiles(dirInput);

	// Extract the data per file and save it in vectors
	std::vector<BankAccountEntry> setOfBankAccountEntries=ImportBankAccountEntries(listOfInputFiles);

	// Define categories and rules
	std::vector<Category> setOfCategories=ImportCategories();

	// Categorize data using the predefined rules. Check every bank entry object on the rules until you find a hit.
	CategorizeBankAccountEntries(setOfBankAccountEntries,setOfCategories);

	// Post processing of categories.
//	setOfCategories[0].PrintSetOfBankAccountEntryIndices(); // TEST.
//	std::vector<BankAccountEntry*> setOfBankAccountEntries2=setOfCategories[0].GetSetOfBankAccountEntries(); // TEST.
//	setOfBankAccountEntries2[0]->printToConsole(); // TEST.

	std::cout<<"\n\nEnd of program.\n\n";
	return 0;
}

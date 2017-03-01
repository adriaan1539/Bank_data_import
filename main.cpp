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
#include <iostream>
#include "ListOfFiles.h"
#include <regex>
#include <string>
#include <vector>

bool ShellInName(BankAccountEntry bankAccountEntry)
{
	bool compliantWithRule=false;
	std::string nameOrDescription=bankAccountEntry.nameOrDescription;
	std::size_t found=nameOrDescription.find("SHELL");

	// the BankAccountEntry is compliant if the string is found
	if (found!=std::string::npos)
	{
		compliantWithRule=true;
	}

	return compliantWithRule;
}

int main (void)
{
	// List files we will import to extract data from. We should make this an input argument of the program later
	std::string dirInput="input";
	std::vector<std::string> listOfInputFiles=ListOfFiles(dirInput);

	// Extract the data per file and save it in vectors
	std::vector<BankAccountEntry> setOfBankAccountEntries=ImportBankAccountEntries(listOfInputFiles);

	// Define categories and rules
	std::vector<Category> setOfCategories;
	Category gasoline("gasoline");
	std::function<bool(BankAccountEntry)> shellInNameFunction=ShellInName;	
	Rule shellInNameRule(shellInNameFunction,"Shell in name.");
	gasoline.AddRule(shellInNameRule);
	
	// Add categories to 'setOfCategories'
	setOfCategories.push_back(gasoline);
	setOfCategories[0].PrintNameOfAllRules();

	// Categorize data using the predefined rules. Check every bank entry object on the rules until you find a hit.
	CategorizeBankAccountEntries(setOfBankAccountEntries,setOfCategories);

	// Post processing of categories.
	// ...
	//setOfCategories[0].PrintSetOfBankAccountEntryIndices();

	
	
	std::cout<<"\n\nEnd of program.\n\n";
	return 0;
}

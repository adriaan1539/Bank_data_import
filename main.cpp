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
	std::string subString="SHELL";
	std::size_t found=nameOrDescription.find(subString);
	std::cout<<"\n\nChecking rule 'ShellInName'.\n\n"; // TEST.
	if (0<=found && found<=nameOrDescription.size()-1)
	{
		compliantWithRule=true;
	}

	return compliantWithRule;
}

int main (void)
{
	// List files we will import to extract data from. We should make this an input argument of the program later.
	std::string dirInput="input";
	std::vector<std::string> listOfInputFiles=ListOfFiles(dirInput);

	// Extract the data per file and save it in vectors.
	std::vector<BankAccountEntry> setOfBankAccountEntries=ImportBankAccountEntries(listOfInputFiles);

	// Define categories and rules. WE SHOULD CONSTRUCT THIS BETTER LATER, SUCH THAT THE RULES ARE INPUT FOR THE MAIN PROGRAM.
	std::vector<Category> setOfCategories;
	Category gasoline("gasoline");
	std::function<bool(BankAccountEntry)> shellInNameFunction=ShellInName;	
	Rule shellinNameRule(shellInNameFunction,"Shell in name.");
	gasoline.AddRule(shellinNameRule);
	
	// Add categories to 'setOfCategories'.
	setOfCategories.push_back(gasoline);
	setOfCategories[0].PrintNameOfAllRules(); // TEST. ??? Why is this test not working? ???

	// Categorize data using the predefined rules. Check every bank entry object on the rules until you find a hit.
	CategorizeBankAccountEntries(setOfBankAccountEntries,setOfCategories);

	// Post processing of categories.
	// ...
	//setOfCategories[0].PrintSetOfBankAccountEntryIndices(); // TEST. ??? Why is this test not working? ???

	std::cout<<"\n\nHello world.\n\n";
	
	std::cout<<"\n\nEnd of program.\n\n";
	return 0;
}

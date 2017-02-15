#include "BankAccountEntry.h"
#include "BankAccountEntryFormat.h"
#include "BankAccountEntryParser.h"
#include "boost/filesystem/operations.hpp"
#include "boost/filesystem/path.hpp"
#include "boost/progress.hpp"
#include "Category.h"
#include <fstream>
#include "ImportBankAccountEntries.h"
#include <iostream>
#include "ListOfFiles.h"
#include <regex>
#include <string>
#include <vector>

int main (void)
{
	// List files we will import to extract data from. We should make this an input argument of the program later.
	std::string dirInput="input";
	std::vector<std::string> listOfInputFiles=ListOfFiles(dirInput);

	// Extract the data per file and save it in vectors.
	std::vector<BankAccountEntry> setOfBankAccountEntries=ImportBankAccountEntries(listOfInputFiles);
	
	// Define rules. WE SHOULD CONSTRUCT THIS BETTER LATER, SUCH THAT THE RULES ARE INPUT FOR THE MAIN PROGRAM.
	std::vector<Category> setOfCategories;
	Category gasoline("gasoline");
	setOfCategories.push_back(gasoline);
	std::function<void(int)> shellInNameFunction; // ??? At the moment, I have no idea how I should define such a function to get what I want. ???
	///Rule shellinNameRule(shellInNameFunction); // ??? I get 'Segmentation fault (core dumped)' error. What is wrong with this command? ???

	// Categorize data using the predefined rules. Check every bank entry object on the rules until you find a hit.
	bool booleanRule=false;
	BankAccountEntry bankAccountEntry;
	Category category;
	std::vector<Rule> setOfRules;
	Rule rule;

	for (unsigned int iBankAccountEntry=0;iBankAccountEntry<setOfBankAccountEntries.size();iBankAccountEntry++)
	{
		std::cout<<"Processing bank entry "<<iBankAccountEntry<<" of "<<setOfBankAccountEntries.size()<<".\n";

		booleanRule=false; // Reset per instance of BankAccountEntry.

		bankAccountEntry=setOfBankAccountEntries[iBankAccountEntry];

		/*
		for (unsigned int iCategory=0;iCategory<setOfCategories.size();iCategory++)
		{
			category=setOfCategories[iCategory];
			setOfRules=category.setOfRules;
			for (unsigned int iRule=0;iRule<setOfRules.size();iRule++)
			{
				rule=setOfRules[iRule];
				// Check 'bankAccountEntry' for 'rule'. If true, the continue to next instance of class BankAccountEntry.
				if (booleanRule==true)
				{
					bankAccountEntry.setIndexCategoryAndRule(iCategory,iRule);
					category.setIndexBankAccountEntry(iBankAccountEntry);
				}
			}
		}
		*/

		if (booleanRule==false)
		{
			std::cout<<"Unable to categorize this bank account entry.\n";
		}
	}

	// Post processing of categories.
	// ...

	std::cout<<"\n\nHello world.\n\n";
	
	std::cout<<"\n\nEnd of program.\n\n";
	return 0;
}

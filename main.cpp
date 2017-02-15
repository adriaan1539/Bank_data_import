#include "BankAccountEntry.h"
#include "BankAccountEntryFormat.h"
#include "BankAccountEntryParser.h"
#include "boost/filesystem/operations.hpp"
#include "boost/filesystem/path.hpp"
#include "boost/progress.hpp"
#include <fstream>
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
	std::string inputFile;
	std::ifstream inputFileStream;
	std::string line;
	std::string subLine;
	std::vector<std::string> subLines;
	BankAccountEntryParser bankAccountEntryParser;
	std::vector<BankAccountEntry> setOfBankAccountEntries;

	// Loop over all input bank data files to construct instances of the class BankAccountEntry.
	for (unsigned int i=0;i<listOfInputFiles.size();i++)
	{
		inputFile=listOfInputFiles[i];
		inputFileStream.open(inputFile); // Define 'inputFileStream' by means of the data file 'inputFile'
		if (inputFileStream.is_open())
		{
			getline(inputFileStream,line); // To skip the first line of a data file.
			while (getline(inputFileStream,line)) // Extract a single line 'line' from the ifstream 'inputFileStream' per step in the while loop.
			{
				BankAccountEntry bankAccountEntry=bankAccountEntryParser.ParseLine(line,BankAccountEntryFormat::ING);
				bankAccountEntry.printToFile("consoleOutput.txt");
				setOfBankAccountEntries.push_back(bankAccountEntry);
			}
			inputFileStream.close();
		}
		else
		{ 
			std::cout<<"\n\nUnable to open file.\n\n";
		}
	}
	
	// Define rules. WE SHOULD CONSTRUCT THIS BETTER LATER, SUCH THAT THE RULES ARE INPUT FOR THE MAIN PROGRAM.
	// ...

	// Categorize data using the predefined rules. Check every bank entry object on the rules until you find a hit.
	/*
	bool booleanRule=false;
	BankAccountEntry bankAccountEntry;
	Category category;
	std::vector<Rule> setOfRules;
	Rule rule;

	for (unsigned int iBankAccountEntry=0;iBankAccountEntry<setOfBankAccountEntries.size();iBankAccountEntry++)
	{
		std::cout<<"Processing bank entry "<<iBankAccountEntry<<" of "<<setOfBankAccountEntries.size()<<".\n"]);

		booleanRule=false; // Reset per instance of BankAccountEntry.

		bankAccountEntry=setOfBankAccountEntries[iBankAccountEntry];
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

		if (booleanRule==false)
		{
			std::cout<<"Unable to categorize this bank account entry.\n";
		}
	}
	 */

	// Post processing of categories.
	// ...

	std::cout<<"\n\nHello world.\n\n";
	
	return 0;
}

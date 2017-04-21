#include "BankAccountEntry.h"
#include "BankAccountEntryFormat.h"
#include "BankAccountEntryParser.h"
#include "BankAccountEntryStringFunctions.h"
#include "ExportBankAccountEntries.h"
#include "boost/filesystem/operations.hpp"
#include "boost/filesystem/path.hpp"
#include "boost/progress.hpp"
#include "CategorizeBankAccountEntries.h"
#include "Category.h"
#include "ExportBankAccountEntries.h"
#include "ExportCategoriesVsAmounts.h"
#include <fstream>
#include "ImportBankAccountEntries.h"
#include "ImportCategories.h"
#include <iostream>
#include "ListOfFiles.h"
#include <regex>
#include <string>
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

	// Save data for post processing.
	std::string dirOutput="output";
	std::string fileName=dirOutput.append("/bar_chart_category_vs_amounts/categoryAmounts.txt");
	ExportBankAccountEntries(setOfBankAccountEntries,fileName);
	//ExportCategoriesVsAmounts(setOfCategories,fileName);

	// Export the bank account data to a CSV file.
	std::string OUTPUT_FILE = "output/out.csv";
	std::cout << "Exporting to " << OUTPUT_FILE << std::endl;
	ExportBankAccountEntries(setOfBankAccountEntries, OUTPUT_FILE);

	std::cout << "\n\nEnd of program." << std::endl;
	return 0;
}

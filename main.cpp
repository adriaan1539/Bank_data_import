#include "BankAccountEntry.h"
#include "BankAccountEntryFormat.h"
#include "BankAccountEntryParser.h"
#include "boost/filesystem/operations.hpp"
#include "boost/filesystem/path.hpp"
#include "boost/progress.hpp"
#include "CategorizeBankAccountEntries.h"
#include "Category.h"
#include "ExportCategoriesVsAmounts.h"
#include "FilterOnDateRange.h"
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

	// Filter on given date ranges as given by the user. !!! SHOULD BE GIVEN AS INPUT TO THE MAIN FUNCTION LATER. !!!
	std::vector<int> dateRange={2016,1,1,
								2016,12,31};
	FilterOnDateRange(setOfBankAccountEntries,dateRange);

	// Define categories and rules
	std::vector<Category> setOfCategories=ImportCategories();

	// Categorize data using the predefined rules. Check every bank entry object on the rules until you find a hit.
	CategorizeBankAccountEntries(setOfBankAccountEntries,setOfCategories);

	// Save data for post processing.
	std::string dirOutput="output";
	std::string fileName=dirOutput.append("/bar_chart_category_vs_amounts/categoryAmounts.txt");
	ExportCategoriesVsAmounts(setOfCategories,fileName);

	std::cout<<"\n\nEnd of program.\n\n";
	return 0;
}

#include <algorithm>
#include "BankAccountEntry.h"
#include "BankAccountEntrySetBalance.h"
#include "ExportBankAccountEntries.h"
#include "CategorizeBankAccountEntriesUserDefined.h"
#include "CategorizeBankAccountEntriesDefault.h"
#include "Category.h"
#include "ConfigurationParser.h"
#include "ExportBankAccountEntries.h"
#include "ExportCategories.h"
#include "ImportBankAccountEntries.h"
#include <iostream>
#include "ListOfFiles.h"
#include <map>
#include "SortByDate.cpp"
#include <string>
#include <tuple>
#include <vector>

const std::string INPUT_DIR="input";
const std::string CONFIGURATION_FILE = "config.xml";
const std::string OUTPUT_DIR="postProcessing/output";
const std::string OUTPUT_FILE = OUTPUT_DIR + "/bankAccountEntries.csv";
const std::string CATEGORY_OUTPUT_FILE = OUTPUT_DIR + "/categories.csv";
const char* POST_PROCESSOR = "cd postProcessing && python3 Main.py && cd ..";

int main (void)
{
	std::cout<<"Start of program.\n\n";

	// List files we will import to extract data from.
	std::cout<<"Reading files from directory '"<<INPUT_DIR<<"':"<<std::endl;
	std::vector<std::string> listOfInputFiles=ListOfFiles(INPUT_DIR);

	// Extract the data per file and save it in vectors.
	std::vector<BankAccountEntry> setOfBankAccountEntries=ImportBankAccountEntries(listOfInputFiles);

	// Sort the bank account entries by year, then by month, then by day.
	std::sort(setOfBankAccountEntries.begin(), setOfBankAccountEntries.end(), SortByDate());

	// Determine balance for every bank account entry by asking the user to give the balance at the time of the last bank account entry.
	BankAccountEntrySetBalance(setOfBankAccountEntries);

	// Categorize bank account data using default categories.
	auto result = CategorizeBankAccountEntriesDefault(setOfBankAccountEntries);

	// Load categories from configuration file.
	ConfigurationParser ruleConfiguration;
	ruleConfiguration.LoadConfigurationFromFile(CONFIGURATION_FILE);

	// Define categories and rules.
	std::vector<Category> setOfCategories = ruleConfiguration.GetCategories();

	// Categorize bank account data using user defined categories.
	std::cout<<"\nCategorize bank account entries using user defined categories.\n";
	CategorizeBankAccountEntriesUserDefined(setOfBankAccountEntries,setOfCategories);

	// Export the bank account data, now categorized, to a CSV file.
	std::cout << "\nExporting bank account entries to " << OUTPUT_FILE << ".\n	";
	std::map<std::string, std::vector<int>> categories;
	categories = ExportBankAccountEntries(setOfBankAccountEntries, OUTPUT_FILE);

	// Export the categories + bank accounts
	std::cout<<"\nExporting categories to "<<CATEGORY_OUTPUT_FILE<<".\n\n";
	ExportCategories(categories, CATEGORY_OUTPUT_FILE);

	// Run post processor.
	std::cout<<"\nRunning post processor.\n\n=";
	system(POST_PROCESSOR);

	std::cout << "\n\nEnd of program." << std::endl;
	return 0;
}

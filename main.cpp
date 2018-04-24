#include <algorithm>
#include "BankAccountEntry.h"
#include "BankAccountEntrySetBalance.h"
#include "ExportBankAccountEntries.h"
#include "CategorizeBankAccountEntriesUserDefined.h"
#include "CategorizeBankAccountEntriesDefault.h"
#include "Category.h"
#include "ConfigurationParser.h"
#include "DateToDayOfWeek.h"
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
const std::string CATEGORY_ADDITIONORSUBTRACTION_OUTPUT_FILE = OUTPUT_DIR + "/additionOrSubtraction.csv";
const std::string CATEGORY_CODE_OUTPUT_FILE = OUTPUT_DIR + "/code.csv";
const std::string CATEGORY_DAY_OUTPUT_FILE = OUTPUT_DIR + "/day.csv";
const std::string CATEGORY_DAYOFTHEWEEK_OUTPUT_FILE = OUTPUT_DIR + "/dayOfTheWeek.csv";
const std::string CATEGORY_MONTH_OUTPUT_FILE = OUTPUT_DIR + "/month.csv";
const std::string CATEGORY_MUTATION_OUTPUT_FILE = OUTPUT_DIR + "/mutation.csv";
const std::string CATEGORY_YEAR_OUTPUT_FILE = OUTPUT_DIR + "/year.csv";
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
	std::cout<<"\nCategorize bank account entries using the default categories.\n";
	auto categoriesDefault = CategorizeBankAccountEntriesDefault(setOfBankAccountEntries);

	// Export default category data to CSV.
	std::cout<<"\nExporting default categories.\n\n";
	ExportCategories(categoriesDefault.additionOrSubtractionToBankAccountEntryIndicesTemp, CATEGORY_ADDITIONORSUBTRACTION_OUTPUT_FILE);
	ExportCategories(categoriesDefault.codeToBankAccountEntryIndicesTemp, CATEGORY_CODE_OUTPUT_FILE);
	ExportCategories(categoriesDefault.dayToBankAccountEntryIndicesTemp, CATEGORY_DAY_OUTPUT_FILE);
	ExportCategories(categoriesDefault.dayOfTheWeekToBankAccountEntryIndicesTemp, CATEGORY_DAYOFTHEWEEK_OUTPUT_FILE);
	ExportCategories(categoriesDefault.monthToBankAccountEntryIndicesTemp, CATEGORY_MONTH_OUTPUT_FILE);
	ExportCategories(categoriesDefault.mutationToBankAccountEntryIndicesTemp, CATEGORY_MUTATION_OUTPUT_FILE);
	ExportCategories(categoriesDefault.yearToBankAccountEntryIndicesTemp, CATEGORY_YEAR_OUTPUT_FILE);

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

	// Export the categories + bank accounts.
	std::cout<<"\nExporting categories to "<<CATEGORY_OUTPUT_FILE<<".\n\n";
	ExportCategories(categories, CATEGORY_OUTPUT_FILE);

	// Run post processor.
//	std::cout<<"\nRunning post processor.\n\n=";
//	system(POST_PROCESSOR);

//	for (int i=0;i<10;i++)
//	{
//		std::cout<<i<<std::endl;
//	}

	std::cout << "\n\nEnd of program." << std::endl;
	return 0;
}

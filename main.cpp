#include "BankAccountEntry.h"
#include "ExportBankAccountEntries.h"
#include "CategorizeBankAccountEntries.h"
#include "Category.h"
#include "ExportBankAccountEntries.h"
#include "ExportCategories.h"
#include "ImportBankAccountEntries.h"
#include <iostream>
#include "ListOfFiles.h"
#include "ConfigurationParser.h"
#include <string>
#include <vector>
#include <map>

const std::string INPUT_DIR="input";
const std::string CONFIGURATION_FILE = "config.xml";
const std::string OUTPUT_DIR="postProcessing/output";
const std::string OUTPUT_FILE = OUTPUT_DIR + "/bankAccountEntries.csv";
const std::string CATEGORY_OUTPUT_FILE = OUTPUT_DIR + "/categories.csv";

int main (void)
{
	std::cout<<"Start of program.\n\n";

	// List files we will import to extract data from.
	std::cout<<"Reading files from directory '"<<INPUT_DIR<<"':"<<std::endl;
	std::vector<std::string> listOfInputFiles=ListOfFiles(INPUT_DIR);

	// Load categories from configuration file.
	ConfigurationParser ruleConfiguration;
	ruleConfiguration.LoadConfigurationFromFile(CONFIGURATION_FILE);

	// Extract the data per file and save it in vectors
	std::vector<BankAccountEntry> setOfBankAccountEntries=ImportBankAccountEntries(listOfInputFiles);

	// Define categories and rules
	std::vector<Category> setOfCategories =ruleConfiguration.GetCategories();

	// Categorize data using the predefined rules. Check every bank entry object on the rules until you find a hit.
	CategorizeBankAccountEntries(setOfBankAccountEntries,setOfCategories);

	// Export the bank account data to a CSV file.
	std::cout << "Exporting to " << OUTPUT_FILE << std::endl;
	std::map<std::string, std::vector<int>> categories;
	categories = ExportBankAccountEntries(setOfBankAccountEntries, OUTPUT_FILE);

	// Export the categories + bank accounts
	ExportCategories(categories, CATEGORY_OUTPUT_FILE);

	std::cout << "\n\nEnd of program." << std::endl;
	return 0;
}

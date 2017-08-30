#include <algorithm>
#include "BankAccountEntry.h"
#include "ExportBankAccountEntries.h"
#include "CategorizeBankAccountEntries.h"
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

	// Load categories from configuration file.
	ConfigurationParser ruleConfiguration;
	ruleConfiguration.LoadConfigurationFromFile(CONFIGURATION_FILE);

	// Extract the data per file and save it in vectors
	std::vector<BankAccountEntry> setOfBankAccountEntries=ImportBankAccountEntries(listOfInputFiles);
	std::sort(setOfBankAccountEntries.begin(), setOfBankAccountEntries.end(), SortByDate());

	// Determine balance for every bank account entry by asking the user to give the balance at the time of the last bank account entry.
//	Balance(&setOfBankAccountEntries);




	BankAccountEntry* bankAccountEntryLast = &setOfBankAccountEntries[setOfBankAccountEntries.size()-1];
	std::cout<<"The last bank account entry is: \n\n"<<bankAccountEntryLast->ToCSV(0)<<"\n\n";
	std::cout<<"What was the balance at the time of this bank account entry?\n";
	double balance;
	std::cin>>balance;
	bankAccountEntryLast->SetBalance(balance);
	BankAccountEntry* bankAccountEntryOneLater;
	double balanceOneLater;
	BankAccountEntry* bankAccountEntry;
	double amount;
	for (int iBankAccountEntry=setOfBankAccountEntries.size()-2;iBankAccountEntry>=0;iBankAccountEntry--)
	{
		bankAccountEntryOneLater=&setOfBankAccountEntries[iBankAccountEntry+1];
		balanceOneLater=bankAccountEntryOneLater->GetBalance();
		amount=bankAccountEntryOneLater->GetAmount();
		bankAccountEntry=&setOfBankAccountEntries[iBankAccountEntry];
		bankAccountEntry->SetBalance(balanceOneLater-amount);
	}

	// Define categories and rules
	std::vector<Category> setOfCategories =ruleConfiguration.GetCategories();

	// Categorize data using the predefined rules.
	std::cout<<"\nCategorize bank account entries.\n";
	CategorizeBankAccountEntries(setOfBankAccountEntries,setOfCategories);

	// Export the bank account data to a CSV file.
	std::cout << "\nExporting bank account entries to " << OUTPUT_FILE << ".\n	";
	std::map<std::string, std::vector<int>> categories;
	categories = ExportBankAccountEntries(setOfBankAccountEntries, OUTPUT_FILE);

	// Export the categories + bank accounts
	std::cout<<"\nExporting categories to "<<CATEGORY_OUTPUT_FILE<<".\n\n";
	ExportCategories(categories, CATEGORY_OUTPUT_FILE);

	// Run post processor.
	std::cout<<"\nRunning post processor.\n\n=";
//	system(POST_PROCESSOR);

	std::cout << "\n\nEnd of program." << std::endl;
	return 0;
}

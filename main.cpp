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
#include "StringInName.h"
#include <vector>

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

	std::vector<std::string> gasolineNames;

	std::function<bool(BankAccountEntry)> benzineInNameFunction=[](BankAccountEntry bankAccountEntry){return StringInName(bankAccountEntry,"BENZINE");};
	Rule benzineInNameRule(benzineInNameFunction,"BENZINE in name.");
	gasoline.AddRule(benzineInNameRule);

	std::function<bool(BankAccountEntry)> bpInNameFunction=[](BankAccountEntry bankAccountEntry){return StringInName(bankAccountEntry,"BP");};Rule bpInNameRule(bpInNameFunction,"BP in name.");gasoline.AddRule(bpInNameRule);
	std::function<bool(BankAccountEntry)> brandstofInNameFunction=[](BankAccountEntry bankAccountEntry){return StringInName(bankAccountEntry,"BRANDSTOF");};Rule brandstofInNameRule(brandstofInNameFunction,"BRANDSTOF in name.");gasoline.AddRule(brandstofInNameRule);
	std::function<bool(BankAccountEntry)> delfortInNameFunction=[](BankAccountEntry bankAccountEntry){return StringInName(bankAccountEntry,"DELFORT");};Rule delfortInNameRule(delfortInNameFunction,"DELFORT in name.");gasoline.AddRule(delfortInNameRule);
	std::function<bool(BankAccountEntry)> easyInNameFunction=[](BankAccountEntry bankAccountEntry){return StringInName(bankAccountEntry,"EASY ENERGYMETAALHOF");};Rule easyInNameRule(easyInNameFunction,"EASY ENERGYMETAALHOF in name.");gasoline.AddRule(easyInNameRule);
	std::function<bool(BankAccountEntry)> essoInNameFunction=[](BankAccountEntry bankAccountEntry){return StringInName(bankAccountEntry,"ESSO");};Rule essoInNameRule(essoInNameFunction,"ESSO in name.");gasoline.AddRule(essoInNameRule);
	std::function<bool(BankAccountEntry)> gabrielsInNameFunction=[](BankAccountEntry bankAccountEntry){return StringInName(bankAccountEntry,"GABRIELS 48 ESSEN");};Rule gabrielsInNameRule(gabrielsInNameFunction,"GABRIELS 48 ESSEN in name.");gasoline.AddRule(gabrielsInNameRule);
	std::function<bool(BankAccountEntry)> gulfInNameFunction=[](BankAccountEntry bankAccountEntry){return StringInName(bankAccountEntry,"GULF");};Rule gulfInNameRule(gulfInNameFunction,"GULF in name.");gasoline.AddRule(gulfInNameRule);
	std::function<bool(BankAccountEntry)> schipperInNameFunction=[](BankAccountEntry bankAccountEntry){return StringInName(bankAccountEntry,"SCHIPPER");};Rule schipperInNameRule(schipperInNameFunction,"SCHIPPER in name.");gasoline.AddRule(schipperInNameRule);
	std::function<bool(BankAccountEntry)> shellInNameFunction=[](BankAccountEntry bankAccountEntry){return StringInName(bankAccountEntry,"SHELL");};Rule shellInNameRule(shellInNameFunction,"SHELL in name.");gasoline.AddRule(shellInNameRule);
	std::function<bool(BankAccountEntry)> tamoilInNameFunction=[](BankAccountEntry bankAccountEntry){return StringInName(bankAccountEntry,"TAMOIL");};Rule tamoilInNameRule(tamoilInNameFunction,"TAMOIL in name.");gasoline.AddRule(tamoilInNameRule);
	std::function<bool(BankAccountEntry)> tangoInNameFunction=[](BankAccountEntry bankAccountEntry){return StringInName(bankAccountEntry,"TANGO");};Rule tangoInNameRule(shellInNameFunction,"TANGO in name.");gasoline.AddRule(tangoInNameRule);
	std::function<bool(BankAccountEntry)> tankInNameFunction=[](BankAccountEntry bankAccountEntry){return StringInName(bankAccountEntry,"TANK");};Rule tankInNameRule(tankInNameFunction,"TANK in name.");gasoline.AddRule(tankInNameRule);
	std::function<bool(BankAccountEntry)> texacoInNameFunction=[](BankAccountEntry bankAccountEntry){return StringInName(bankAccountEntry,"TEXACO");};Rule texacoInNameRule(texacoInNameFunction,"TEXACO in name.");gasoline.AddRule(texacoInNameRule);
	std::function<bool(BankAccountEntry)> tinqInNameFunction=[](BankAccountEntry bankAccountEntry){return StringInName(bankAccountEntry,"TINQ");};Rule tinqInNameRule(tinqInNameFunction,"TINQ in name.");gasoline.AddRule(tinqInNameRule);
	std::function<bool(BankAccountEntry)> totalInNameFunction=[](BankAccountEntry bankAccountEntry){return StringInName(bankAccountEntry,"TOTAL");};Rule totalInNameRule(totalInNameFunction,"TOTAL in name.");gasoline.AddRule(totalInNameRule);
	std::function<bool(BankAccountEntry)> vanthartInNameFunction=[](BankAccountEntry bankAccountEntry){return StringInName(bankAccountEntry,"VAN T HART");};Rule vanthartInNameRule(vanthartInNameFunction,"VAN T HART in name.");gasoline.AddRule(vanthartInNameRule);

	// Add categories to 'setOfCategories'
	setOfCategories.push_back(gasoline);
	//setOfCategories[0].PrintNameOfAllRules(); // TEST.

	// Categorize data using the predefined rules. Check every bank entry object on the rules until you find a hit.
	CategorizeBankAccountEntries(setOfBankAccountEntries,setOfCategories);

	// Post processing of categories.
	//setOfCategories[0].PrintSetOfBankAccountEntryIndices(); // TEST.
	//std::vector<BankAccountEntry*> setOfBankAccountEntries2=setOfCategories[0].GetSetOfBankAccountEntries(); // TEST.
	//setOfBankAccountEntries2[0]->printToConsole(); // TEST.
	
	std::cout<<"\n\nEnd of program.\n\n";
	return 0;
}

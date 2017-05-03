#include "ImportCategories.h"
#include "BankAccountEntryStringFunctions.h"

void AddRulesToCategory(std::string ruleName,
						std::function<bool(BankAccountEntry, std::string)> ruleFunction,
						std::vector<std::string> args,
						Category& category)
{
	for (unsigned int i=0; i<args.size(); i++)
	{
		std::string arg=args[i];
		std::function<bool(BankAccountEntry)> localFunction=[arg,ruleFunction](BankAccountEntry bankAccountEntry){return ruleFunction(bankAccountEntry, arg);};
		Rule rule(localFunction, arg.append(" found."));
		category.AddRule(rule);
	}
}

Category CreateCategory(std::string categoryName,
						std::vector<std::function<bool(BankAccountEntry, std::string)>> ruleFunctions,
						std::vector<std::string> setOfRuleNames,
						std::vector<std::vector<std::string>> setOfRuleArgs)
{
	Category category(categoryName);
	for (unsigned int i=0; i<ruleFunctions.size(); i++)
	{
		std::vector<std::string> ruleArgs = setOfRuleArgs[i];
		std::string ruleName = setOfRuleNames[i];
		AddRulesToCategory(ruleName, ruleFunctions[i], ruleArgs, category);
	}
	return category;
}

// Rule function: stringInName
std::function<bool(BankAccountEntry, std::string)> stringInNameRuleFunction
		= [](BankAccountEntry bankAccountEntry, std::string searchTerm) -> bool {	return StringInName(bankAccountEntry, searchTerm);};

// Rule function: stringInNote
std::function<bool(BankAccountEntry, std::string)> stringInNoteRuleFunction
		= [](BankAccountEntry bankAccountEntry, std::string searchTerm) -> bool {	return StringInNote(bankAccountEntry, searchTerm);};

std::vector<Category> ImportCategories()
{
	std::vector<std::function<bool(BankAccountEntry, std::string)>> functions = {stringInNameRuleFunction,stringInNoteRuleFunction};
	std::vector<std::string> functionNames = {"in name or description","in note"};

	std::vector<Category> setOfCategories;

//	Gasoline.
	std::vector<std::string> gasolineNames={"BENZINE",
											"BP",
											"BRANDSTOF",
											"DELFORT",
											"EASY ENERGYMETAALHOF",
											"ESSO",
											"GABRIELS 48 ESSEN",
											"GULF",
											"SCHIPPER",
											"SHELL",
											"TAMOIL",
											"TANGO",
											"TANK",
											"TEXACO",
											"TINQ",
											"TOTAL",
											"VAN T HART"};
	std::vector<std::vector<std::string>> gasolineArgs={gasolineNames,gasolineNames};

	Category gasoline = CreateCategory(	"gasoline",
										functions,
										functionNames,
										gasolineArgs);
	setOfCategories.push_back(gasoline);

////	Mortgage.
//	std::vector<std::vector<std::string>> mortgageNames={{"AEGON"}};
//	Category mortgage = CreateCategory("mortgage", functions, functionNames, mortgageNames);
//	setOfCategories.push_back(mortgage);
//
////	Supermarket.
//	std::vector<std::vector<std::string>> superMarketNames={{"ALBERT HEIJN",
//												"C1000",
//												"CASTELEIJN BROOD",
//												"COOP",
//												"DEN TOOM",
//												"EXTRAMARKT",
//												"HEIJDEN",
//												"JUMBO",
//												"LIDL"}};
//	Category supermarket = CreateCategory("supermarket", functions, functionNames, superMarketNames);
//	setOfCategories.push_back(supermarket);
	return setOfCategories;
}

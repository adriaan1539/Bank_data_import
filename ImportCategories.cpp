#include "ImportCategories.h"
#include "StringInName.h"

Category CreateNameCategory(std::string categoryName, std::vector<std::string> names){
	Category category(categoryName);
	for (unsigned int iNames=0;iNames<names.size();iNames++)
	{
		std::string name=names[iNames];
		std::function<bool(BankAccountEntry)> inNameFunction=[name](BankAccountEntry bankAccountEntry){return StringInName(bankAccountEntry,name);};
		Rule inNameRule(inNameFunction,name.append(" in name."));
		category.AddRule(inNameRule);
	}
	return category;
}

std::vector<Category> ImportCategories()
{
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
	Category gasoline = CreateNameCategory("gasoline", gasolineNames);
	setOfCategories.push_back(gasoline);

//	Mortgage.
	std::vector<std::string> mortgageNames={"AEGON"};
	Category mortgage = CreateNameCategory("mortgage", mortgageNames);
	setOfCategories.push_back(mortgage);

//	Supermarket.
	std::vector<std::string> superMarketNames={	"ALBERT HEIJN",
												"C1000",
												"CASTELEIJN BROOD",
												"COOP",
												"DEN TOOM",
												"EXTRAMARKT",
												"HEIJDEN",
												"JUMBO",
												"LIDL"};
	Category supermarket = CreateNameCategory("supermarket", superMarketNames);
	setOfCategories.push_back(supermarket);
	return setOfCategories;
}

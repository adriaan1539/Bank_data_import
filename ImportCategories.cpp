#include "ImportCategories.h"
#include "StringInName.h"

std::vector<Category> ImportCategories()
{
	std::vector<Category> setOfCategories;

//	Gasoline.
	Category gasoline("gasoline");
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

	for (unsigned int iGasolineNames=0;iGasolineNames<gasolineNames.size();iGasolineNames++)
	{
		std::string gasolineName=gasolineNames[iGasolineNames];
		std::function<bool(BankAccountEntry)> inNameFunction=[gasolineName](BankAccountEntry bankAccountEntry){return StringInName(bankAccountEntry,gasolineName);};
		Rule inNameRule(inNameFunction,gasolineName.append(" in name."));
		gasoline.AddRule(inNameRule);
	}
	setOfCategories.push_back(gasoline);

//	Mortgage.
	Category mortgage("mortgage");
	std::vector<std::string> mortgageNames={"AEGON"};

	for (unsigned int iMortgageNames=0;iMortgageNames<mortgageNames.size();iMortgageNames++)
	{
		std::string mortgageName=mortgageNames[iMortgageNames];
		std::function<bool(BankAccountEntry)> inNameFunction=[mortgageName](BankAccountEntry bankAccountEntry){return StringInName(bankAccountEntry,mortgageName);};
		Rule inNameRule(inNameFunction,mortgageName.append(" in name."));
		mortgage.AddRule(inNameRule);
	}
	setOfCategories.push_back(mortgage);

//	Supermarket.
	Category superMarket("supermarket");
	std::vector<std::string> superMarketNames={	"ALBERT HEIJN",
												"C1000",
												"CASTELEIJN BROOD",
												"COOP",
												"DEN TOOM",
												"EXTRAMARKT",
												"HEIJDEN",
												"JUMBO",
												"LIDL"};

	for (unsigned int iSuperMarketNames=0;iSuperMarketNames<superMarketNames.size();iSuperMarketNames++)
	{
		std::string superMarketName=superMarketNames[iSuperMarketNames];
		std::function<bool(BankAccountEntry)> inNameFunction=[superMarketName](BankAccountEntry bankAccountEntry){return StringInName(bankAccountEntry,superMarketName);};
		Rule inNameRule(inNameFunction,superMarketName.append(" in name."));
		superMarket.AddRule(inNameRule);
	}
	setOfCategories.push_back(superMarket);

	return setOfCategories;
}

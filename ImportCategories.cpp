#include "ImportCategories.h"
#include "StringInName.h"

std::vector<Category> ImportCategories()
{
	std::vector<Category> setOfCategories;
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

	// Add categories to 'setOfCategories'
	setOfCategories.push_back(gasoline);

	return setOfCategories;
}

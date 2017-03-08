#include "StringInName.h"

bool StringInName(BankAccountEntry bankAccountEntry,std::string searchTerm)
{
	bool compliantWithRule=false;
	std::string nameOrDescription=bankAccountEntry.nameOrDescription;
	std::size_t found=nameOrDescription.find(searchTerm);

	// The BankAccountEntry is compliant if the string is found
	if (found!=std::string::npos)
	{
		compliantWithRule=true;
	}

	return compliantWithRule;
}

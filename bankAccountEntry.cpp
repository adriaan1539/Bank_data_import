#include "bankAccountEntry.h"
#include "replaceSubStringWithSubString.h"

bankAccountEntry::bankAccountEntry(std::string commaSeparatedValueDataLine)
{

}

bankAccountEntry::bankAccountEntry(std::vector<std::string> subLines)
{
	std::string yyyymmdd=subLines[0];
	year=stoi(yyyymmdd.substr(0,4));
	month=stoi(yyyymmdd.substr(4,2));
	day=stoi(yyyymmdd.substr(6,2));
	nameOrDescription=subLines[1];
	accountNumberConsidered=subLines[2];
	accountNumberContra=subLines[3];
	code=subLines[4];
	amount=replaceSubStringWithSubString(stoi(subLines[6]),",","."); // The ',' has to be replaced with a '.'.
	sortOfMutation=subLines[7];
	note=subLines[8];
}

// ??? I used the suffix 'Input' to distinguish the input arguments from the private member variables. How is this normally done ???
bankAccountEntry::bankAccountEntry(	unsigned int yearInput,
									unsigned int monthInput,
									unsigned int dayInput,
									std::string nameOrDescriptionInput,
									std::string accountNumberConsideredInput,
									std::string accountNumberContraInput,
									std::string codeInput,
									double amountInput,
									std::string sortOfMutationInput,
									std::string noteInput)
{
	year=yearInput;
	month=monthInput;
	day=dayInput;
	nameOrDescription=nameOrDescriptionInput;
	accountNumberConsidered=accountNumberConsideredInput;
	accountNumberContra=accountNumberContraInput;
	code=codeInput;
	amount=amountInput;
	sortOfMutation=sortOfMutationInput;
	note=noteInput;
}

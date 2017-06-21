#include "BankAccountEntryStringFunctions.h"

bool AccountNumberConsideredEqualTo(BankAccountEntry bankAccountEntry,
									std::string searchTerm)
{
	bool compliantWithRule=false;
	std::string accountNumberConsidered=bankAccountEntry.GetAccountNumberConsidered();
	std::size_t found=accountNumberConsidered.find(searchTerm);

	// The BankAccountEntry is compliant if the string is found.
	if (found!=std::string::npos)
	{
		compliantWithRule=true;
	}

	return compliantWithRule;
}

bool AccountNumberContraEqualTo(BankAccountEntry,std::string)
{
	bool compliantWithRule=false;
	return compliantWithRule;
}

bool AmountLargerThan(BankAccountEntry,double,double)
{
	bool compliantWithRule=false;
	return compliantWithRule;
}

bool AmountSmallerThan(BankAccountEntry,double,double)
{
	bool compliantWithRule=false;
	return compliantWithRule;
}

bool CodeEqualTo(BankAccountEntry,std::string)
{
	bool compliantWithRule=false;
	return compliantWithRule;
}

bool DayLargerThan(BankAccountEntry,int)
{
	bool compliantWithRule=false;
	return compliantWithRule;
}

bool DaySmallerThan(BankAccountEntry,int)
{
	bool compliantWithRule=false;
	return compliantWithRule;
}

bool MonthLargerThan(BankAccountEntry,int){
	bool compliantWithRule=false;
	return compliantWithRule;
}

bool MonthSmallerThan(BankAccountEntry,int)
{
	bool compliantWithRule=false;
	return compliantWithRule;
}

bool MutationEqualTo(BankAccountEntry,std::string)
{
	bool compliantWithRule=false;
	return compliantWithRule;
}

bool StringInName(	BankAccountEntry bankAccountEntry,
					std::string searchTerm)
{
	bool compliantWithRule=false;
	std::string nameOrDescription=bankAccountEntry.GetNameOrDescription();
	std::size_t found=nameOrDescription.find(searchTerm);

	// The BankAccountEntry is compliant if the string is found
	if (found!=std::string::npos)
	{
		compliantWithRule=true;
	}

	return compliantWithRule;
}

bool StringInNote(	BankAccountEntry bankAccountEntry,
					std::string searchTerm)
{
	bool compliantWithRule=false;
	std::string note=bankAccountEntry.GetNote();
	std::size_t found=note.find(searchTerm);

	// The BankAccountEntry is compliant if the string is found
	if (found!=std::string::npos)
	{
		compliantWithRule=true;
	}

	return compliantWithRule;
}


bool YearLargerThan(BankAccountEntry,int)
{
	bool compliantWithRule=false;
	return compliantWithRule;
}

bool YearSmallerThan(BankAccountEntry,int)
{
	bool compliantWithRule=false;
	return compliantWithRule;
}

#include "BankAccountEntryFilterFunctions.h"

bool AccountNumberConsideredEqualTo(BankAccountEntry bankAccountEntry,
									std::string searchTerm)
{
	bool compliantWithRule=false;
	std::string accountNumberConsidered=bankAccountEntry.GetAccountNumberConsidered();
	std::size_t found=accountNumberConsidered.find(searchTerm);

	if (found!=std::string::npos)
	{
		compliantWithRule=true;
	}

	return compliantWithRule;
}

bool AccountNumberContraEqualTo(BankAccountEntry bankAccountEntry,
								std::string searchTerm)
{
	bool compliantWithRule=false;
	std::string accountNumberContra=bankAccountEntry.GetAccountNumberContra();
	std::size_t found=accountNumberContra.find(searchTerm);

	if (found!=std::string::npos)
	{
		compliantWithRule=true;
	}
	return compliantWithRule;
}

bool AmountBetweenAndEqualTo(	BankAccountEntry bankAccountEntry,
								double lowerBound,
								double upperBound)
{
	bool compliantWithRule=false;
	double amount=bankAccountEntry.GetAmount();
	if (lowerBound<=amount && amount<=upperBound)
	{
		compliantWithRule=true;
	}

	return compliantWithRule;
}

bool CodeEqualTo(BankAccountEntry bankAccountEntry,std::string searchTerm)
{
	bool compliantWithRule=false;
	std::string code=bankAccountEntry.GetCode();
	std::size_t found=code.find(searchTerm);

	if (found!=std::string::npos)
	{
		compliantWithRule=true;
	}

	return compliantWithRule;
}

bool DateBetweenAndEqual(	BankAccountEntry bankAccountEntry,
							unsigned int lowerBoundYear,
							unsigned int lowerBoundMonth,
							unsigned int lowerBoundDay,
							unsigned int upperBoundYear,
							unsigned int upperBoundMonth,
							unsigned int upperBoundDay)
{
	bool compliantWithRule=false;
	unsigned int day=bankAccountEntry.GetDay();
	unsigned int month=bankAccountEntry.GetMonth();
	unsigned int year=bankAccountEntry.GetYear();
	if (lowerBoundDay<=day && day<= upperBoundDay &&
		lowerBoundMonth<=month && month<= upperBoundMonth &&
		lowerBoundYear<=year && year<= upperBoundYear)
	{
		compliantWithRule=true;
	}

	return compliantWithRule;
}

bool MutationEqualTo(	BankAccountEntry bankAccountEntry,
						std::string searchTerm)
{
	bool compliantWithRule=false;
	std::string sortOfMutation=bankAccountEntry.GetSortOfMutation();
	std::size_t found=sortOfMutation.find(searchTerm);

	if (found!=std::string::npos)
	{
		compliantWithRule=true;
	}

	return compliantWithRule;
}

bool StringInName(	BankAccountEntry bankAccountEntry,
					std::string searchTerm)
{
	bool compliantWithRule=false;
	std::string nameOrDescription=bankAccountEntry.GetNameOrDescription();
	std::size_t found=nameOrDescription.find(searchTerm);

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

	if (found!=std::string::npos)
	{
		compliantWithRule=true;
	}

	return compliantWithRule;
}

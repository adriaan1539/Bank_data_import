#include "BankAccountEntry.h"

BankAccountEntry::BankAccountEntry(	unsigned int year,
									unsigned int month,
									unsigned int day,
									std::string nameOrDescription,
									std::string accountNumberConsidered,
									std::string accountNumberContra,
									std::string code,
									double amount,
									std::string sortOfMutation,
									std::string note)
{
	this->year=year;
	this->month=month;
	this->day=day;
	this->nameOrDescription=nameOrDescription;
	this->accountNumberConsidered=accountNumberConsidered;
	this->accountNumberContra=accountNumberContra;
	this->code=code;
	this->amount=amount;
	this->sortOfMutation=sortOfMutation;
	this->note=note;
}

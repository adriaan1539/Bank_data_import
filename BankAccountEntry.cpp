#include "BankAccountEntry.h"
#include <iostream>

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

void BankAccountEntry::printToConsole(void)
{
	std::cout<<"year: "<<year<<"\n";
	std::cout<<"month: "<<month<<"\n";
	std::cout<<"day: "<<day<<"\n";
	std::cout<<"nameOrDescription: "<<nameOrDescription<<"\n";
	std::cout<<"accountNumberConsidered: "<<accountNumberConsidered<<"\n";
	std::cout<<"accountNumberContra: "<<accountNumberContra<<"\n";
	std::cout<<"code: "<<code<<"\n";
	std::cout<<"amount: "<<amount<<"\n";
	std::cout<<"sortOfMutation: "<<sortOfMutation<<"\n";
	std::cout<<"note: "<<note<<"\n\n";
}

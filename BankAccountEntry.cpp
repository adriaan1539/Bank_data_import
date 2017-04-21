#include "BankAccountEntry.h"
#include <fstream>
#include <iostream>
#include "minicsv.h"

BankAccountEntry::BankAccountEntry()
{
}

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

double BankAccountEntry::GetAmount(void)
{
	return amount;
}

std::string BankAccountEntry::GetNameOrDescription(void)
{
	return nameOrDescription;
}

std::string BankAccountEntry::GetNote(void)
{
	return note;
}

std::string BankAccountEntry::ToCSV(void)
{
	mini::csv::ostringstream os;
	os.set_delimiter(',', "\\,");

	os << this->year
			<< this->month
			<< this->day
			<< this->nameOrDescription
			<< this->accountNumberConsidered
			<< this->accountNumberContra
			<< this->code
			<< this->amount
			<< this->sortOfMutation
			<< this->note;

	return os.get_text();
}

unsigned int BankAccountEntry::GetDay(void)
{
	return day;
}

unsigned int BankAccountEntry::GetMonth(void)
{
	return month;
}

unsigned int BankAccountEntry::GetYear(void)
{
	return year;
}

void BankAccountEntry::PrintToConsole(void)
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

void BankAccountEntry::PrintToFile(std::string fileName)
{
	std::ofstream outputFileStream;
	outputFileStream.open(fileName,std::ios::app);
	
	outputFileStream<<"year: "<<year<<"\n";
	outputFileStream<<"month: "<<month<<"\n";
	outputFileStream<<"day: "<<day<<"\n";
	outputFileStream<<"nameOrDescription: "<<nameOrDescription<<"\n";
	outputFileStream<<"accountNumberConsidered: "<<accountNumberConsidered<<"\n";
	outputFileStream<<"accountNumberContra: "<<accountNumberContra<<"\n";
	outputFileStream<<"code: "<<code<<"\n";
	outputFileStream<<"amount: "<<amount<<"\n";
	outputFileStream<<"sortOfMutation: "<<sortOfMutation<<"\n";
	outputFileStream<<"note: "<<note<<"\n\n";
	
	outputFileStream.close();
}

void BankAccountEntry::SetIndexCategoryAndRule(	Category* category,
												Rule* rule)
{
	this->category=category;
	this->rule=rule;
}

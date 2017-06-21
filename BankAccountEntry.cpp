#include "BankAccountEntry.h"
#include "JoinVectorToString.h"
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

std::string	BankAccountEntry::GetAccountNumberConsidered(void)
{
	return accountNumberConsidered;
}

std::string	BankAccountEntry::GetAccountNumberContra(void)
{
	return accountNumberContra;
}

std::string BankAccountEntry::GetCategoryNames(void)
{
	return JoinVector(this->categories, ";");
}

std::string	BankAccountEntry::GetCode(void)
{
	return code;
}

std::string BankAccountEntry::GetNameOrDescription(void)
{
	return nameOrDescription;
}

std::string BankAccountEntry::GetNote(void)
{
	return note;
}

std::string BankAccountEntry::GetRuleNames(void)
{
	return JoinVector(this->rules, ";");
}

std::string	BankAccountEntry::GetSortOfMutation(void)
{
	return code;
}

std::string BankAccountEntry::ToCSV(int index)
{
	mini::csv::ostringstream os;
	os.set_delimiter(',', "\\,");

	os << index
			<< this->year
			<< this->month
			<< this->day
			<< this->nameOrDescription
			<< this->accountNumberConsidered
			<< this->accountNumberContra
			<< this->code
			<< this->amount
			<< this->sortOfMutation
			<< this->note
			<< this->GetCategoryNames()
			<< this->GetRuleNames();

	return os.get_text();
}

std::vector<std::string> BankAccountEntry::GetCategories()
{
	return this->categories;
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

void BankAccountEntry::AddCategoryAndRuleName(std::string category, std::string rule)
{
	this->categories.push_back(category);
	this->rules.push_back(rule);
}

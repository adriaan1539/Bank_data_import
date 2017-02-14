#include "BankAccountEntryParser.h"
#include <iostream>
#include <regex>
#include "ReplaceSubStringWithSubString.h"
#include <stdexcept>
#include <vector>

// Definition function 'ParseLine', member of class 'BankAccountEntryParser'.
BankAccountEntry BankAccountEntryParser::ParseLine(	std::string line,
													std::map<std::string,int> format)
{
	std::regex re("\"(.*?)\""); // Define regular expression to extract substrings for string below.
	std::regex_iterator<std::string::iterator> it (line.begin(),line.end(),re);
	std::regex_iterator<std::string::iterator> end; // The default constructor of 'std::regex_iterator<std::string::iterator>' is the end-of-sequence iterator.
	std::cout<<std::endl<<std::endl<<"Line: "<<line; // Print the whole line that is considered.
	std::vector<std::string> lineParts;
	std::string linePart="";

	// Split 'line' into line parts and save these in the vector 'lineParts'.
	while (it!=end)
	{
		linePart=it->str(1); // Note the necessity of the '1' to exclude the double quotes from the string.
		std::cout<<linePart<<std::endl; // Print substring.
		lineParts.push_back(linePart);
		++it;
	}

	// Some auxilliary commands for the construction of an instance of 'BankAccountEntry'.
	std::string transactionDate=lineParts[format["date"]];
	std::string additionOrSubtractionString=lineParts[5];
	double additionOrSubtractionDouble;
	if (additionOrSubtractionString.compare("Af")==0)
	{
		additionOrSubtractionDouble=-1.0;
	}
	else if (additionOrSubtractionString.compare("Bij")==0)
	{
		additionOrSubtractionDouble=1.0;
	}
	else
	{
		std::cout<<"\n\nERROR: Unable to determine sign of amount.\n\n";
		throw std::invalid_argument("The double 'additionOrSubtractionDouble' is not properly defined.");
	}
	std::string amountString=lineParts[format["amount"]];
	amountString=ReplaceSubStringWithSubString(amountString,",","."); // Replace the Dutch ",", for decimals in a double, with a ".".
	double amount=std::stod(amountString); // Type casting of string into double.
	amount=additionOrSubtractionDouble*amount; // Correct the sign of the amount.

	// ??? Why is 'std::stoi' needed for type casting instead of '(int)', like we do with '(std::string)' ???
	return BankAccountEntry(std::stoi(transactionDate.substr(0,4)),
							std::stoi(transactionDate.substr(4,2)),
							std::stoi(transactionDate.substr(6,2)),
							(std::string) lineParts[format["description"]],
							(std::string) lineParts[format["accountNumber"]],
							(std::string) lineParts[format["accountNumberContra"]],
							(std::string) lineParts[format["code"]],
							amount,
							(std::string) lineParts[format["sortOfMutation"]],
							(std::string) lineParts[format["note"]]);
}

#ifndef BANKACCOUNTENTRYPARSER_H
#define BANKACCOUNTENTRYPARSER_H

#include "BankAccountEntry.h"
#include "BankAccountEntryFormat.h"
#include <map>
#include <string>
#include <vector>

class BankAccountEntryParser
{
	private:
		double GetAmount(	std::vector<std::string>,
							std::map<std::string,int>);
		std::vector<std::string> GetLineParts(std::string);
	protected:
	public:
		BankAccountEntry ParseLine(	std::string line,
									std::map<std::string,int> formatMap);
};
#endif

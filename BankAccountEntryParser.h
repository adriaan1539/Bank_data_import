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
		std::vector<std::string> GetLineParts(std::string line);
	protected:
	public:
		BankAccountEntry ParseLine(std::string line,
									std::map<std::string,int> formatMap);
};
#endif

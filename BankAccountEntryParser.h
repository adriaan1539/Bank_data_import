#ifndef BANKACCOUNTENTRYPARSER_H
#define BANKACCOUNTENTRYPARSER_H

#include "BankAccountEntry.h"
#include "BankAccountEntryFormat.h"
#include <map>
#include <string>

class BankAccountEntryParser
{
	private:
	protected:
	public:
		BankAccountEntry ParseLine(	std::string line,
									std::map<std::string,int> formatMap);
};
#endif

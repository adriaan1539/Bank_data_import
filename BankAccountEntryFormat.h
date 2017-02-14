#ifndef BANKACCOUNTENTRYFORMAT_H
#define BANKACCOUNTENTRYFORMAT_H

#include <map>
#include <string>

namespace BankAccountEntryFormat
{
	const std::map<std::string,int> ING=
	{
		{"date", 0},
		{"description", 1},
		{"accountNumber", 2},
		{"accountNumberContra", 3},
		{"code", 4},
		{"amount", 6},
		{"sortOfMutation", 7},
		{"note", 8},
	};
}
#endif

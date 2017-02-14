#ifndef BANKACCOUNTENTRYFORMAT_H
#define BANKACCOUNTENTRYFORMAT_H

#include <map>
#include <string>

namespace BankAccountEntryFormat
{
	const std::map<std::string,int> ING=
	{
		{"date",0},
		{"description",1},
		{"accountNumber",2},
		{"accountNumberContra",3},
		{"code",4},
		{"additionOrSubtraction", 5},
		{"amount",6},
		{"sortOfMutation",7},
		{"note",8}
	};

	const std::map<std::string,int> RABO=
	{
		{"accountNumber",0},
		{"date",2},
		{"amount",4},
		{"accountNumberContra",5},
		{"additionOrSubtraction", 5},
		{"description",10},
		{"note",11}
	};
}
#endif

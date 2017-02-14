#ifndef BANKACCOUNTENTRY_H
#define BANKACCOUNTENTRY_H

#include <string>

class BankAccountEntry
{
	private:
		unsigned int year;
		unsigned int month;
		unsigned int day;
		std::string nameOrDescription;
		std::string accountNumberConsidered;
		std::string  accountNumberContra;
		std::string code;
		double amount;
		std::string sortOfMutation;
		std::string note;
	protected:
	public:
		BankAccountEntry(	unsigned int year,
							unsigned int month,
							unsigned int day,
							std::string nameOrDescription,
							std::string accountNumberConsidered,
							std::string accountNumberContra,
							std::string code,
							double amount,
							std::string sortOfMutation,
							std::string note);
};
#endif

#ifndef RULE_H
#define RULE_H

#include "BankAccountEntry.h"
#include <functional>
#include <string>
#include <vector>

class Rule
{
	private:
		std::string name;
	protected:
	public:
		Rule();
		Rule(std::function<bool(BankAccountEntry)> rule,std::string nameRule);
		std::function<bool(BankAccountEntry)> ruleFunction;
		std::string GetNameRule();
};
#endif

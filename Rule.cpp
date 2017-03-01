#include "Rule.h"
#include <iostream>

Rule::Rule()
{
}

Rule::Rule(	std::function<bool(BankAccountEntry)> rule,
			std::string nameRule)
{
	this->ruleFunction=rule;
	this->name=nameRule;
}

std::string Rule::GetNameRule()
{
	return name;
}

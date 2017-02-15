#ifndef CATEGORY_H
#define CATEGORY_H

#include <functional>
#include <string>
#include <vector>

class Rule; // Forward declaration. Necessary because class Rule is used in class Category.

class Category
{
	private:
		std::string nameCategory;
	protected:
		std::vector<Rule> setOfRules;
	public:
		Category();
		Category(std::string nameCategory);
		void setIndexBankAccountEntry(unsigned int iBankAccountEntry);
};

class Rule : public Category
{
	private:
		std::function<void(int)> rule;
	protected:
	public:
		Rule();
		Rule(std::function<void(int)> rule);
};
#endif

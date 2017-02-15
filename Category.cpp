#include "Category.h"

Category::Category()
{
}

Category::Category(std::string nameCategory)
{
	this->nameCategory=nameCategory;
}

Rule::Rule()
{
}

Rule::Rule(std::function<void(int)> rule)
{
	setOfRules.push_back(rule);
}

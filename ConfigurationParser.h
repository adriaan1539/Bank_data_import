/*
 * RuleConfigurationParser.h
 *
 *  Created on: May 23, 2017
 *      Author: terry.seidler
 */

#ifndef CONFIGURATIONPARSER_H_
#define CONFIGURATIONPARSER_H_

#include "Category.h"
#include "Rule.h"
#include "pugixml.hpp"
#include <map>
#include <vector>

class ConfigurationParser
{
	private:
		std::vector<Rule> 					rules;
		std::map<std::string, Category> 	categories;
		pugi::xml_document					configurationFile;

		void 		AddRuleToCategory(pugi::xml_node&, Category&);
		void		LoadCategories();
		void		MakeSureCategoryExists(std::string);

	public:
		ConfigurationParser();

		void 					LoadConfigurationFromFile(std::string);
		std::vector<Category> 	GetCategories();

};

#endif /* CONFIGURATIONPARSER_H_ */

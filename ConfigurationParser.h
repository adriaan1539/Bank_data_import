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
#include <vector>

class ConfigurationParser
{
	private:
		std::vector<Rule> 		rules;
		std::vector<Category> 	categories;
		pugi::xml_document		configurationFile;

		void 		LoadRules();
		void		LoadCategories();

	public:
		ConfigurationParser();

		void 		LoadConfigurationFromFile(std::string filename);

};

#endif /* CONFIGURATIONPARSER_H_ */

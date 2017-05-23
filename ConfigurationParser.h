/*
 * RuleConfigurationParser.h
 *
 *  Created on: May 23, 2017
 *      Author: terry.seidler
 */

#ifndef CONFIGURATIONPARSER_H_
#define CONFIGURATIONPARSER_H_

#include "Rule.h"
#include "pugixml.hpp"
#include <vector>

class ConfigurationParser
{
	private:
		std::vector<Rule> 	rules;
		pugi::xml_document	configurationFile;

	public:
		ConfigurationParser();

		void 		LoadRulesFromFile(std::string filename);

};

#endif /* CONFIGURATIONPARSER_H_ */

/*
 * RuleConfigurationParser.h
 *
 *  Created on: May 23, 2017
 *      Author: terry.seidler
 */

#ifndef RULECONFIGURATIONPARSER_H_
#define RULECONFIGURATIONPARSER_H_

#include "Rule.h"
#include "pugixml.hpp"
#include <vector>

class RuleConfigurationParser
{
	private:
		std::vector<Rule> 	rules;
		pugi::xml_document	configurationFile;

	public:
		RuleConfigurationParser();

		void 		LoadRulesFromFile(std::string filename);

};

#endif /* RULECONFIGURATIONPARSER_H_ */

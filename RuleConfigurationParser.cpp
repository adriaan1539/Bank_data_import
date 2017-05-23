#include "RuleConfigurationParser.h"
#include <iostream>

RuleConfigurationParser::RuleConfigurationParser() {
	this->rules = std::vector<Rule>();
}

void RuleConfigurationParser::LoadRulesFromFile(std::string filename) {
	pugi::xml_parse_result result = this->configurationFile.load_file(filename.c_str());

	std::cout << "Rule Configuration load result: " << result.description() << ", mesh name: " << this->configurationFile.child("mesh").attribute("name").value() << std::endl;
}

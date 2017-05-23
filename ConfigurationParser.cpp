#include "ConfigurationParser.h"
#include <iostream>

ConfigurationParser::ConfigurationParser() {
	this->rules = std::vector<Rule>();
	this->categories = std::vector<Category>();
}

void ConfigurationParser::LoadConfigurationFromFile(std::string filename) {
	pugi::xml_parse_result result = this->configurationFile.load_file(filename.c_str());

	std::cout << "Rule Configuration load result: " << result.description() << ", ruleset name: " << this->configurationFile.child("config").child("rules").attribute("name").value() << std::endl;

	if(result) {
		std::cout << "Loading categories... ";
		this->LoadCategories();
		std::cout << "done! " << this->categories.size() << " categories loaded.";
	}
}

void ConfigurationParser::LoadRules() {

}

void ConfigurationParser::LoadCategories() {
	for(pugi::xml_node category: this->configurationFile.child("config").child("categories").children()) {
		this->categories.push_back(Category(category.value()));
	}
}

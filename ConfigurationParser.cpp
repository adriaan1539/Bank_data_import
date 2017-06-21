#include "BankAccountEntryFilterFunctions.h"
#include "ConfigurationParser.h"
#include <iostream>

// Rule function: stringInName
std::function<bool(BankAccountEntry, std::string)> stringInNameRuleFunction
		= [](BankAccountEntry bankAccountEntry, std::string searchTerm) -> bool {	return StringInName(bankAccountEntry, searchTerm);};

// Rule function: stringInNote
std::function<bool(BankAccountEntry, std::string)> stringInNoteRuleFunction
		= [](BankAccountEntry bankAccountEntry, std::string searchTerm) -> bool {	return StringInNote(bankAccountEntry, searchTerm);};

ConfigurationParser::ConfigurationParser() {
	this->rules = std::vector<Rule>();
	this->categories = std::map<std::string, Category>();
}

std::vector<Category> ConfigurationParser::GetCategories() {
	std::vector <Category> categoriesVector;

	for(std::map<std::string, Category>::iterator it = this->categories.begin(); it != this->categories.end(); ++it) {
		categoriesVector.push_back(it->second);
	}
	return categoriesVector;
}

void ConfigurationParser::LoadConfigurationFromFile(std::string filename) {
	pugi::xml_parse_result result = this->configurationFile.load_file(filename.c_str());

	if(result) {
		std::cout << "Loading categories..." << std::endl;
		this->LoadCategories();
		std::cout << "done! " << this->categories.size() << " categories loaded." << std::endl;
	} else {
		std::cout << "!! ERROR loading categories" << std::endl;
	}
}

void ConfigurationParser::LoadCategories() {
	for(pugi::xml_node category: this->configurationFile.child("config").child("categories").children()) {
		std::string categoryName = category.attribute("name").value();
		std::cout << ":: Loading Category " << categoryName << std::endl;
		this->MakeSureCategoryExists(categoryName);

		for(pugi::xml_node ruleNode: category.child("rules").children()) {
			this->AddRuleToCategory(ruleNode, this->categories[categoryName]);
		}
	}
}

void ConfigurationParser::AddRuleToCategory(pugi::xml_node &ruleNode, Category &category) {
	std::function<bool(BankAccountEntry, std::string)> ruleFunction;
	std::string functionName = ruleNode.child("function").child_value();



	if(functionName == "StringInName") {
		ruleFunction = [](BankAccountEntry bankAccountEntry, std::string searchTerm) -> bool {	return StringInName(bankAccountEntry, searchTerm);};
	} else if(functionName == "StringInNote") {
		ruleFunction = [](BankAccountEntry bankAccountEntry, std::string searchTerm) -> bool {	return StringInNote(bankAccountEntry, searchTerm);};
	} else {
		std::cout << "!!!! ERROR: function does not exist: " << functionName << std::endl;
		return;
	}

	std::cout << ":::: Loading rule " << functionName << std::endl;

	for(pugi::xml_node functionArg: ruleNode.child("values").children()) {
		std::string arg=functionArg.child_value();
		std::function<bool(BankAccountEntry)> localFunction=[arg,ruleFunction](BankAccountEntry bankAccountEntry){return ruleFunction(bankAccountEntry, arg);};
		Rule rule(localFunction, functionName);
		category.AddRule(rule);
	}
}

void ConfigurationParser::MakeSureCategoryExists(std::string categoryName) {
	if(this->categories.count(categoryName) == 0) {
		this->categories[categoryName] = Category(categoryName);
	}
}

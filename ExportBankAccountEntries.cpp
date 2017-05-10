#include "ExportBankAccountEntries.h"
#include <fstream>

std::map<std::string, std::vector<int>> ExportBankAccountEntries(std::vector<BankAccountEntry>& setOfBankAccountEntries,
							  std::string& fileName)
{
	std::map<std::string, std::vector<int>> categories;

	std::ofstream output;
	output.open(fileName, std::ofstream::out | std::ofstream::trunc);

	for (unsigned int i=0; i < setOfBankAccountEntries.size(); i++)
	{
		BankAccountEntry bae = setOfBankAccountEntries[i];
		output << bae.ToCSV(i) << "\n";

		std::string category = bae.GetCategoryNames();
		if(category != "") {
			if(categories.find(category) == categories.end()) {
				categories.insert(std::pair<std::string, std::vector<int>>(category, std::vector<int> {i}));
			} else {
				categories[category].push_back(i);
			}
		}
	}
	return categories;
}

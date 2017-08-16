#include <algorithm>
#include "ExportBankAccountEntries.h"
#include <fstream>

struct sortByDate
{
    inline bool operator() (const BankAccountEntry& bae1, const BankAccountEntry& bae2)
    {
    	bool result = false;
    	if (bae1.GetYear() < bae2.GetYear())
    	{
    		result = true;
    	}
    	else if (bae1.GetYear() == bae2.GetYear() && bae1.GetMonth() < bae2.GetMonth())
    	{
    		result = true;
    	}
    	else if (bae1.GetYear() == bae2.GetYear() && bae1.GetMonth() == bae2.GetMonth() && bae1.GetDay() < bae2.GetDay())
    	{
    		result = true;
    	}
    	return result;
    }
};

std::map<std::string, std::vector<int>> ExportBankAccountEntries(std::vector<BankAccountEntry>& setOfBankAccountEntries,
							  	  	  	  	  	  	  	  	  	 const std::string& fileName)
{
	std::map<std::string, std::vector<int>> categories;

	std::ofstream output;
	output.open(fileName, std::ofstream::out | std::ofstream::trunc);

	std::sort(setOfBankAccountEntries.begin(), setOfBankAccountEntries.end(), sortByDate());

	for (unsigned int i=0; i < setOfBankAccountEntries.size(); i++)
	{
		BankAccountEntry bae = setOfBankAccountEntries[i];
		output << bae.ToCSV(i) << "\n";

		std::vector<std::string> categoryNames = bae.GetCategories();
		for(unsigned int ci=0; ci<categoryNames.size(); ci++) {
			std::string category = categoryNames[ci];
			if(category != "") {
				if(categories.find(category) == categories.end()) {
					categories.insert(std::pair<std::string, std::vector<int>>(category, std::vector<int> {i}));
				} else {
					categories[category].push_back(i);
				}
			}
		}
	}
	return categories;
}

#include "ExportBankAccountEntries.h"
#include <fstream>

void ExportBankAccountEntries(std::vector<BankAccountEntry>& setOfBankAccountEntries,
							  std::string& fileName)
{
	std::ofstream output;
	output.open(fileName, std::ofstream::out | std::ofstream::trunc);

	for (unsigned int i=0; i < setOfBankAccountEntries.size(); i++)
	{
		output << setOfBankAccountEntries[i].ToCSV() << "\n";
	}
}

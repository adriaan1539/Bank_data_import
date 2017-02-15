#include "BankAccountEntry.h"
#include "BankAccountEntryParser.h"
#include <fstream>
#include "ImportBankAccountEntries.h"
#include <iostream>
#include <string>
#include <vector>

std::vector<BankAccountEntry> ImportBankAccountEntries(std::vector<std::string> listOfInputFiles)
{
	std::string inputFile;
	std::ifstream inputFileStream;
	std::string line;
	std::string subLine;
	std::vector<std::string> subLines;
	BankAccountEntryParser bankAccountEntryParser;
	std::vector<BankAccountEntry> setOfBankAccountEntries;

	// Loop over all input bank data files to construct instances of the class BankAccountEntry.
	for (unsigned int i=0;i<listOfInputFiles.size();i++)
	{
		inputFile=listOfInputFiles[i];
		inputFileStream.open(inputFile); // Define 'inputFileStream' by means of the data file 'inputFile'
		if (inputFileStream.is_open())
		{
			getline(inputFileStream,line); // To skip the first line of a data file.
			while (getline(inputFileStream,line)) // Extract a single line 'line' from the ifstream 'inputFileStream' per step in the while loop.
			{
				BankAccountEntry bankAccountEntry=bankAccountEntryParser.ParseLine(line,BankAccountEntryFormat::ING);
				bankAccountEntry.printToFile("consoleOutput.txt");
				setOfBankAccountEntries.push_back(bankAccountEntry);
			}
			inputFileStream.close();
		}
		else
		{
			std::cout<<"\n\nUnable to open file.\n\n";
		}
	}

	return setOfBankAccountEntries;
}

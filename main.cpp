#include "bankAccountEntry.h"
#include "boost/filesystem/operations.hpp"
#include "boost/filesystem/path.hpp"
#include "boost/progress.hpp"
#include <fstream>
#include <iostream>
#include "listOfFiles.h"
#include <regex>
#include <string>
#include <vector>

int main (void)
{
	// List files we will import to extract data from. We should make this an input argument of the program later.
	std::string dirInput="input";
	std::vector<std::string> listOfInputFiles=listOfFiles(dirInput);
	
	// Extract the data per file and save it in vectors.
	std::string inputFile;
	std::ifstream inputFileStream;
	std::string line;
	std::string subLine;
	std::vector<std::string> subLines;
	std::regex re("\"(.*?)\""); // Define regular expression to extract substrings for string below.

	for (unsigned int i=0;i<listOfInputFiles.size();i++)
	{
		inputFile=listOfInputFiles[i];
		inputFileStream.open(inputFile); // Define 'inputFileStream' by means of the data file 'inputFile'
		if (inputFileStream.is_open())
		{
			getline(inputFileStream,line); // ??? To skip the first line of a data file. But is there a more neat manner to do this? ???
			while (getline(inputFileStream,line)) // Extract a single line 'line' from the ifstream 'inputFileStream' per step in the while loop.
			{
				std::regex_iterator<std::string::iterator> it (line.begin(),line.end(),re);
				std::regex_iterator<std::string::iterator> end;
				std::cout<<std::endl<<std::endl<<"Line: "<<line; // Print the whole line that is considered.
				while (it!=end) // ??? QUESTION 'end' is only declared but not defined, so how can this work ???
				{
					subLine=it->str();
					std::cout<<subLine<<std::endl; // Print substring.
					subLines.push_back(subLine);
					++it;
				}

				/*
				for (unsigned int i=0;i<subLines.size();i++)
				{
					std::cout<<subLines[i];
				}
				*/

				// Make bank entry object out of getline data.
				//bankAccountEntry bae(subLines);
			}
			inputFileStream.close();
		}
		else
		{ 
			std::cout<<"\n\nUnable to open file.\n\n";
		}
	}
	
	// Define rules. WE SHOULD CONSTRUCT THIS BETTER LATER, SUCH THAT THE RULES ARE INPUT FOR THE MAIN PROGRAM.
	// ...
	// Categorize data using the predefined rules. Check every bank entry object on the rules until you find a hit.
	// ...

	// Post processing of categories.
	// ...


	std::cout<<"\n\nHello world.\n\n";
	
	return 0;
}

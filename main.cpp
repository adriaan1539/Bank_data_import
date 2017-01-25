#include "boost/filesystem/operations.hpp"
#include "boost/filesystem/path.hpp"
#include "boost/progress.hpp"
#include <fstream>
#include <iostream>
#include "listOfFiles.h"
#include "split.h"
#include <string>
#include <vector>

int main (void)
{
	// List files we will import to extract data from. We should make this an input argument of the program later.
	std::string dirInput="input";
	std::vector<std::string> listOfInputFiles=listOfFiles(dirInput);
	
	// Extract the data per file and save it in vectors.
	std::string inputFile; // Initialization.
	std::ifstream inputFileStream; // Initialization.
	std::string line; // Initialization.
	std::vector<std::string> subLine; // Initialization.
	char delim=',';
	for (unsigned int i=0;i<listOfInputFiles.size();i++)
	{
		inputFile=listOfInputFiles[i];
		inputFileStream.open(inputFile);
		if (inputFileStream.is_open())
		{
			while (getline(inputFileStream,line))
			{
				std::cout<<line<<"\n";
				subLine=split(line,delim);
				for (unsigned int indexSubLine=0;indexSubLine<subLine.size();indexSubLine++)
				{
					std::cout<<subLine[indexSubLine]<<"\n";
				}

				// Make bank entry object out of getline data.
				// ...
			}
			inputFileStream.close();
		}
		else
		{ 
			std::cout<<"Unable to open file";
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

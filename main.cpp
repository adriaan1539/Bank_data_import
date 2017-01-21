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
	std::string dirInput="input";
	std::vector<std::string> listOfInputFiles=listOfFiles(dirInput);
	
	std::string inputFile; // Initialization.
	std::ifstream inputFileStream; // Initialization.
	std::string line; // Initialization.
	std::vector<std::string> subLine;
	char delim=',';
	for (unsigned int indexListOfInputFiles=0;indexListOfInputFiles<listOfInputFiles.size();indexListOfInputFiles++)
	{
		inputFile=listOfInputFiles[indexListOfInputFiles];
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
			}
			inputFileStream.close();
		}
		else
		{ 
			std::cout<<"Unable to open file";
		}
	}
	
	
	
	



	
	std::cout<<"\n\nHello world.\n\n";
	
	return 0;
}

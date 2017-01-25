#include "boost/filesystem/operations.hpp"
#include "boost/filesystem/path.hpp"
#include "boost/progress.hpp"
#include <fstream>
#include <iostream>
#include "listOfFiles.h"
#include <regex>
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
	std::regex re("\"(.*?)\"");


	for (unsigned int i=0;i<listOfInputFiles.size();i++)
	{
		inputFile=listOfInputFiles[i];
		inputFileStream.open(inputFile);
		if (inputFileStream.is_open())
		{
			while (getline(inputFileStream,line))
			{
				std::regex_iterator<std::string::iterator> it (line.begin(), line.end(), re);
				std::regex_iterator<std::string::iterator> end;
				std::cout<<std::endl<<std::endl<<"Line: "<<line;
				while (it != end)
				{
					std::cout << it->str() << std::endl;
					++it;
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

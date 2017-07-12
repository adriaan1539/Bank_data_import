// The function 'listOfFiles' scans 'dirName' for files and stores the hits in vector of strings 'names'.

// Sources: 
// http://stackoverflow.com/questions/20923456/boost-directory-iterator-example-how-to-list-directory-files-not-recursive/33665492?noredirect=1#comment70710190_33665492
// http://coliru.stacked-crooked.com/a/92c0c52df50cefb1

#include <boost/filesystem.hpp>
#include <boost/range.hpp>
#include <iostream>
#include "ListOfFiles.h"

using namespace boost::filesystem;

std::vector<std::string> ListOfFiles (std::string dirName)
{
    path const p=dirName;
    auto list=[=]{return boost::make_iterator_range(directory_iterator(p),{});};

    // Save entries of 'list' in the vector of strings 'names'.
	std::vector<std::string> names;
	for(auto& entry:list())
	{
		if (!is_directory(entry.path())) // Run only if entry is not a directory.
		{
			names.push_back(entry.path().string());
		}
	}

	// Print the entries of the vector of strings 'names'.
    for (unsigned int indexNames=0;indexNames<names.size();indexNames++)
    {
		std::cout<<"    "<<names[indexNames]<<"\n";
	}

    return names;
}

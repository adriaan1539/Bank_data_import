// Sources: 
// http://stackoverflow.com/questions/20923456/boost-directory-iterator-example-how-to-list-directory-files-not-recursive/33665492?noredirect=1#comment70710190_33665492
// http://coliru.stacked-crooked.com/a/92c0c52df50cefb1
#include <boost/filesystem.hpp>
#include <boost/range.hpp>
#include <iostream>
#include "setOfFunctions.h"

using namespace boost::filesystem;

std::vector<std::string> listOfFiles (std::string dirName)
{
    path const p=dirName;
    auto list = [=] { return boost::make_iterator_range(directory_iterator(p), {}); };

	std::vector<std::string> names;
	for(auto& entry : list())
	{
		names.push_back(entry.path().string());
	}
    
    for (unsigned int indexNames=0;indexNames<names.size();indexNames++)
    {
		std::cout<<names[indexNames]<<"\n";
	}
    
    //std::cout<<"\n\nHello world.\n\n";
    
    return names;
}

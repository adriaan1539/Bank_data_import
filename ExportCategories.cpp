#include "ExportCategories.h"
#include <fstream>
#include "minicsv.h"

std::string JoinIndices(const std::vector<int> & v, const std::string & delimiter) {
    std::string out;
    for(int i=0; i<v.size(); i++) {
    	out.append(std::to_string(v[i])).append(delimiter);
    }
    return out;
}

void ExportCategories(std::map<std::string, std::vector<int>> categories, std::string fileName) {
	 mini::csv::ofstream os(fileName);
	 os.set_delimiter(',', "\\,");
	    if(os.is_open())
	    {
	    	for(auto const& category : categories) {
	        	os << category.first << JoinIndices(category.second, ";");
	        }
	    }
	    os.flush();
}




#include "ExportCategories.h"
#include <fstream>
#include "minicsv.h"
#include "JoinVectorToString.h"

void ExportCategories(std::map<std::string, std::vector<int>> categories, std::string fileName) {
	 mini::csv::ofstream os(fileName);
	 os.set_delimiter(',', ".");
	 if(os.is_open())
	 {
		 for(auto const& category : categories) {
			 os << category.first << JoinVector(category.second, ";") << NEWLINE;
		 }
	 }
	 os.flush();
}




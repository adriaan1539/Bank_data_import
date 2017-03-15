#include "ExportCategoriesVsAmounts.h"
#include <fstream>

void ExportCategoriesVsAmounts(	std::vector<Category>& setOfCategories,
								std::string& fileName)
{
	std::ofstream outputFileStream;
	outputFileStream.open(fileName,std::ios::out);
	outputFileStream<<"category,amountTotal\n";
	for (unsigned int iCategory=0;iCategory<setOfCategories.size();iCategory++)
	{
		Category category=setOfCategories[iCategory];
		std::string name=category.GetName();
		double amountTotal=category.GetAmountTotal();
		outputFileStream<<name<<","<<amountTotal<<"\n";
	}
	outputFileStream.close();
}

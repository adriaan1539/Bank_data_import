#include "BankAccountEntry.h"

struct SortByDate
{
    inline bool operator() (const BankAccountEntry& bae1, const BankAccountEntry& bae2)
    {
    	bool result = false;
    	if (bae1.GetYear() < bae2.GetYear())
    	{
    		result = true;
    	}
    	else if (bae1.GetYear() == bae2.GetYear() && bae1.GetMonth() < bae2.GetMonth())
    	{
    		result = true;
    	}
    	else if (bae1.GetYear() == bae2.GetYear() && bae1.GetMonth() == bae2.GetMonth() && bae1.GetDay() < bae2.GetDay())
    	{
    		result = true;
    	}
    	return result;
    }
};

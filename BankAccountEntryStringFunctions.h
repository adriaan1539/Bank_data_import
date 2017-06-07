#ifndef BANKACCOUNTENTRYSTRINGFUNCTIONS_H
#define BANKACCOUNTENTRYSTRINGFUNCTIONS_H

#include "BankAccountEntry.h"
#include <string>

bool AccountNumberConsideredEqualTo(BankAccountEntry,std::string);
bool AccountNumberContraEqualTo(BankAccountEntry,std::string);
bool AmountLargerThan(BankAccountEntry,double,double);
bool AmountSmallerThan(BankAccountEntry,double,double);
bool CodeEqualTo(BankAccountEntry,std::string);
bool DayLargerThan(BankAccountEntry,int);
bool DaySmallerThan(BankAccountEntry,int);
bool MonthLargerThan(BankAccountEntry,int);
bool MonthSmallerThan(BankAccountEntry,int);
bool MutationEqualTo(BankAccountEntry,std::string);
bool StringInName(BankAccountEntry,std::string);
bool StringInNote(BankAccountEntry,std::string);
bool YearLargerThan(BankAccountEntry,int);
bool YearSmallerThan(BankAccountEntry,int);

#endif

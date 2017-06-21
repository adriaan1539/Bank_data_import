#ifndef BANKACCOUNTENTRYFILTERFUNCTIONS_H
#define BANKACCOUNTENTRYFILTERFUNCTIONS_H

#include "BankAccountEntry.h"
#include <string>

bool AccountNumberConsideredEqualTo(BankAccountEntry,std::string);
bool AccountNumberContraEqualTo(BankAccountEntry,std::string);
bool AmountBetweenAndEqualTo(BankAccountEntry,double,double);
bool CodeEqualTo(BankAccountEntry,std::string);
bool DateBetweenAndEqualTo(BankAccountEntry,unsigned int,unsigned int,unsigned int,unsigned int,unsigned int,unsigned int);
bool MutationEqualTo(BankAccountEntry,std::string);
bool StringInName(BankAccountEntry,std::string);
bool StringInNote(BankAccountEntry,std::string);

#endif

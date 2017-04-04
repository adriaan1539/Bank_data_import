#ifndef BANKACCOUNTENTRYSTRINGFUNCTIONS_H
#define BANKACCOUNTENTRYSTRINGFUNCTIONS_H

#include "BankAccountEntry.h"
#include <string>

bool StringInName(BankAccountEntry,std::string);
bool StringInNote(BankAccountEntry,std::string);

#endif

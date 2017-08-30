#include "BankAccountEntry.h"
#include "BankAccountEntrySetBalance.h"
#include <iostream>

void BankAccountEntrySetBalance(std::vector<BankAccountEntry>& setOfBankAccountEntries)
{
	BankAccountEntry* bankAccountEntryLast = &setOfBankAccountEntries[setOfBankAccountEntries.size()-1];
	std::cout<<"The last bank account entry is: \n\n"<<bankAccountEntryLast->ToCSV(0)<<"\n\n";
	std::cout<<"What was the balance at the time of this bank account entry?\n";
	double balance;
	std::cin>>balance;
	bankAccountEntryLast->SetBalance(balance);
	BankAccountEntry* bankAccountEntryOneLater;
	double balanceOneLater;
	BankAccountEntry* bankAccountEntry;
	double amount;
	for (int iBankAccountEntry=setOfBankAccountEntries.size()-2;iBankAccountEntry>=0;iBankAccountEntry--)
	{
		bankAccountEntryOneLater=&setOfBankAccountEntries[iBankAccountEntry+1];
		balanceOneLater=bankAccountEntryOneLater->GetBalance();
		amount=bankAccountEntryOneLater->GetAmount();
		bankAccountEntry=&setOfBankAccountEntries[iBankAccountEntry];
		bankAccountEntry->SetBalance(balanceOneLater-amount);
	}
}

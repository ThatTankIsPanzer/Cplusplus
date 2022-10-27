#include <iostream>
#include "SavingAccount.h"

using namespace std;



SavingAccount::SavingAccount(double bal, double iRate, double tranFee)
:Account(bal, iRate)
{

    transactFee = tranFee;
}

bool SavingAccount::debit(double withdw)
{
    Account::debit(withdw + transactFee);
    //balance = balance -transactFee;
}

void SavingAccount::print()
{
    cout << "Saving Account:" << endl;
    Account::print();
    cout << "  Transaction fee of withdraw: " << transactFee << endl;

}

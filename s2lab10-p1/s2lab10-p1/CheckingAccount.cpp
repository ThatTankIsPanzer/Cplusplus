#include <iostream>
#include "CheckingAccount.h"

using namespace std;
CheckingAccount::CheckingAccount(double bal, double iRate, double tranFeeW, double tranFeeD):Account(bal, iRate)
{

    transactFeeW=tranFeeW;
    transactFeeD=tranFeeD;

}

bool CheckingAccount::debit(double withdw)
{
    Account::debit(withdw + transactFeeW);
}

void CheckingAccount::credit(double depos)
{
    Account::credit(depos);
    balance = balance - transactFeeD;
}

void CheckingAccount::print()
{
    cout << "Checking Account:" << endl;
    Account::print();
    cout << "  Transaction fee of withdraw: " << transactFeeW << endl;
    cout << "  Transaction fee of Deposit: " << transactFeeD << endl;
}


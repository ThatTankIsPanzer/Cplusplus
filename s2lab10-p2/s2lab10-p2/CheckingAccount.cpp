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
    //Account::debit(withdw + transactFeeW);
    if(withdw + transactFeeW > 0 && withdw + transactFeeW <= balance)
    {
        //cout << "hi" << endl;
        balance = balance - withdw - transactFeeW;
        return true;
    }
    else if(withdw + transactFeeW > balance)
    {
        cout << "  Debit amount exceeded account balance." << endl;
        return false;
    }
    return false;
}

void CheckingAccount::credit(double depos)
{
    //Account::credit(depos);
    if(depos > 0)
        balance = balance + depos;
    balance = balance - transactFeeD;
}

void CheckingAccount::print()
{
    cout << "Checking Account:" << endl;
    //Account::print();
    cout << "  Balance: " << balance << endl;
    cout << "  Interest rate: " <<  interestRate << endl;
    cout << "  Transaction fee of withdraw: " << transactFeeW << endl;
    cout << "  Transaction fee of Deposition: " << transactFeeD << endl;
}


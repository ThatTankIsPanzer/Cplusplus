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
    if(withdw + transactFee > 0 && withdw + transactFee <= balance)
    {
        //cout << "hi" << endl;
        balance = balance - withdw;
        return true;
    }
    else if(withdw + transactFee > balance)
    {
        cout << "  Debit amount exceeded account balance." << endl;
        return false;
    }
    return false;
    //Account::debit(withdw + transactFee);
    //balance = balance -transactFee;
}

void SavingAccount::credit(double depos)
{
    //Account::credit(depos);
    if(depos > 0)
        balance = balance + depos;
    balance = balance - transactFee;
}

void SavingAccount::print()
{
    cout << "Saving Account:" << endl;
    cout << "  Balance: " << balance << endl;
    cout << "  Interest rate: " <<  interestRate << endl;
    //Account::print();
    cout << "  Transaction fee of withdraw: " << transactFee << endl;

}

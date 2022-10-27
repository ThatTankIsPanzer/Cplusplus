#include <iostream>
#include <typeinfo>
#include <vector>
#include "Account.h"
#include "CheckingAccount.h"
#include "SavingAccount.h"
using namespace std;
bool SavingToChecking(SavingAccount& SavA, CheckingAccount& CheA, const double trans)
{
    if(trans > SavA.balance)
    {
        cout << "Transfer transaction fails." << endl;
    }
    else
    {
        CheA.balance = CheA.balance + trans;
        SavA.balance = SavA.balance - trans - SavA.transactFee;
    }
}

bool CheckingToSaving(CheckingAccount& CheA, SavingAccount& SavA, const double trans)
{
    if(trans > CheA.balance)
    {
        cout << "Transfer transaction fails." << endl;
    }
    else
    {
        SavA.balance = trans + SavA.balance;
        CheA.balance = CheA.balance - trans - CheA.transactFeeW;
    }
}
int main()
{
    SavingAccount sAcnt(110.0, 0.05);
    CheckingAccount cAcnt(120.0, 0.02, 4.0, 2.0);
    CheckingAccount c2Acnt(500.0, 0.025, 4.0, 2.0);
    SavingAccount s2Acnt(1000.0, 0.04, 1.0);
    const int numAcc = 4;
    vector <Account *> baseAccount(numAcc);
    baseAccount[0] = &sAcnt;
    baseAccount[1] = &cAcnt;
    baseAccount[2] = &c2Acnt;
    baseAccount[3] = &s2Acnt;
    for(int i = 0; i < numAcc; i++)
    {
        //cout << "\nAccount type =" << typeid(*baseAccount[i]).name() << endl;
        baseAccount[i] -> debit(10.0);
        baseAccount[i] -> credit(50.0);
        baseAccount[i] -> print();
        SavingAccount *sAcntPtr = dynamic_cast<SavingAccount *> (baseAccount[i]);
        if(sAcntPtr != 0)
        {
            sAcntPtr->calculateInterest();
            cout << "Balance of the checking account after adding interest =" << sAcntPtr->getBalance() << endl;
        }
    }
}

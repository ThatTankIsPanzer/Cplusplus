#ifndef SAVINGACCOUNT_H
#define SAVINGACCOUNT_H
#include "Account.h"
using namespace std;
class CheckingAccount;
class SavingAccount : public Account
{
    friend bool SavingToChecking(SavingAccount&, CheckingAccount&, const double);
    friend bool CheckingToSaving(CheckingAccount&, SavingAccount&, const double);
public:
    SavingAccount(double = 0.0, double = 0.0, double = 3.0);
    // parameters: balance, interest rate, transaction fee.
    virtual bool debit(double =0.0);
    //virtual void credit(double =0.0);
    virtual void print();
    void credit(double = 0.0);
private:
    double transactFee; // transaction fee for withdrawing
};
#endif

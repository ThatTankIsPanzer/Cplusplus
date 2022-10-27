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
    bool debit(double =0.0);
    void print();
private:
    double transactFee; // transaction fee for withdrawing
};
#endif

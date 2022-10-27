#ifndef CHECKINGACCOUNT_H
#define CHECKINGACCOUNT_H
#include "Account.h"
using namespace std;
class SavingAccount;
class CheckingAccount : public Account
{
    friend bool SavingToChecking(SavingAccount&, CheckingAccount&, const double);
    friend bool CheckingToSaving(CheckingAccount&, SavingAccount&, const double);
public:
    CheckingAccount(double = 0.0, double =0.0, double =3.0, double = 2.0);
    // Parameters: balance, interest rate, transaction fee for withdraw, transaction fee for deposition
    bool debit(double =0.0); // return true if it can be done successfully.
    void credit(double =0.0);
    void print();
private:
    double transactFeeW; // withdraw
    double transactFeeD; // Deposit
};
#endif

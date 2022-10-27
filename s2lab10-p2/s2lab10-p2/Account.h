#ifndef ACCOUNT_H
#define ACCOUNT_H
using namespace std;

class Account
{
public:
    Account(double = 0.0, double =0.0);//ok
    virtual void credit(double =0.0) = 0; // Deposit money >0
    virtual bool debit(double = 0.0) = 0; // Withdraw money>0
    double getBalance(); // Get balance
    double calculateInterest(); // Return interest and add the interest to the balance
    virtual void print() = 0; // print balance and interest rate
protected:
    double balance; // Account balance >=0
    double interestRate; // Interest rate >=0
};

#endif

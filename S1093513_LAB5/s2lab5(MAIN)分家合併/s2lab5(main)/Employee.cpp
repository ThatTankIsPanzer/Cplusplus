#include <iostream>
#include "Employee.h"
#include "Date.h"
using namespace std;

Employee :: Employee(const string &first, const string &last, const Date &dateOfBirth, const Date &dateOfHire, Date &dateOfDismiss, int Salary)
:firstName(first), lastName(last), birthDate(dateOfBirth), hireDate(dateOfHire), dismissD(dateOfDismiss), monSalary(Salary)
{
   cout << "Employee object constructor: " << firstName << " " << lastName << " Monthly paid: " << monSalary << endl;
}

void Employee :: print() const
{
    cout << lastName << ", " << firstName << "  Hired: ";
    hireDate.print();
    cout << "  Birthday: ";
    birthDate.print();
    cout << "  Month pay: ";
    cout << monSalary;
    cout << "  Dismissing: ";
    dismissD.print();
    cout << endl;
}

Employee &Employee :: eDismiss(Date &dismiss)
{

    if(dismissD.DismissDate(dismiss) == true)
    {
        cout << firstName << " " << lastName <<" with inconsistent dates!\n" << endl;
    }
    dismissD = dismiss;
    return *this;
}

Employee &Employee :: increaseSalary(int Salary)
{
    monSalary += Salary;
    return *this;
}

Employee :: ~Employee()
{
    cout << "Employee object destructor: " << lastName << ", " << firstName << endl;
}


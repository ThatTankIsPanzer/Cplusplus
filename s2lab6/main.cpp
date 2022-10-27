#include <iostream>

using namespace std;

class Employee
{
public:
    //friend void print(const Employee &); //output 1
    friend void print(const Employee); //output 2/3
    Employee(const Employee& );
    Employee( const string &, const string &, char);
    ~Employee();
    string getFirstName() const;
    string getLastName() const;
    char Gender() const;
    static int getCount();
    static int getfCount();
    static int getmCount();
    static void printCount();
    Employee &printFirstName();
    Employee *printLastName();


private:
    string firstName; // composition: member object
    string lastName; // composition: member object
    static int count;
    char gender;
    static int fCount;
    static int mCount;

};

int Employee :: count = 0;
int Employee :: fCount = 0;
int Employee :: mCount = 0;

int Employee :: getCount()
{
    return count;
}

int Employee :: getfCount()
{
    return fCount;
}

int Employee :: getmCount()
{
    return mCount;
}

void Employee :: printCount()
{
    cout << "Number of employees = " << getCount() << " Male employees = " << getmCount()
        <<" Female employees " << getfCount() << endl;
}

Employee :: Employee( const string &first, const string &last, char g): firstName(first), lastName(last), gender(g)
{
    if(g == 'M')
    {
        ++mCount;
    }
    else if(g == 'F')
    {
        ++fCount;
    }
    else
    {
        cout << "Employee's gender specification is incorrect. " << g << endl;
    }
    ++count;
    cout << "Employee constructor for " << firstName << ' ' << lastName << ' ' << "called." << endl;
}

Employee :: ~Employee()
{
    cout << "~Employee() destructor for " << firstName << ' ' << lastName << ' ' << "called." << endl;
    --count;
    if(gender == 'M')
    {
        --mCount;
    }
    else if(gender == 'F')
    {
        --fCount;
    }
}

/*void print(const Employee &e)  //output 1
{
    cout << e.getFirstName() << " " <<e.getLastName() << " " << e.Gender() << endl;
}*/

/*Employee :: Employee(const Employee& e)
 {
    firstName = e.firstName;
    lastName = e.lastName;
    gender = e.gender;
     if(gender == 'M')
    {
        ++mCount;
    }
    else if(gender == 'F')
    {
        ++fCount;
    }
    ++count;
 }*/

void print(const Employee e)
{
    cout << e.getFirstName() << " " <<e.getLastName() << " " << e.Gender() << endl;

}

Employee &Employee :: printFirstName()
{
    cout << firstName << " ";
    return *this;
}

Employee *Employee:: printLastName()
{
    cout << lastName << " ";
    return this;
}

string Employee :: getFirstName() const
{
    return firstName;
}

string Employee :: getLastName() const
{
    return lastName;
}

char Employee :: Gender() const
{
    return gender;
}

int main()
{
    cout << "Number of employees before instantiation of any objects is " << Employee :: getCount() << endl;
    {
        Employee e1("Susan", "Baker", 'M');
        Employee e2("Robert", "Jones", 'F');
        Employee e3("Emily", "Willow", 'F');
        Employee e4("john", "Reid", 'K');
        Employee e5("Maria", "Vinci", 'M');
        Employee e6("Vincent", "Ulr", 'F');
        Employee e7("RB", "Lin", 'M');
        print(e5);
        print(e6);

        cout << "Number of employees after objects are instantiated is " << Employee :: getCount() << endl;
        cout << "\n\nEmployee 1: " << e1.getFirstName() << " " << e1.getLastName() << "\nEmployee 2: "
        << e2.getFirstName() << " " << e2.getLastName() << "\n\n";

        Employee e8("Tomas", "Hwang", 'F');
        Employee e9("James", "Wang", 'F');

        cout << "Number of employees after objects are instantiated is: \n";
        Employee :: printCount();

        cout << "\n\nEmployee 3: ";
            e3.printFirstName().printLastName();
        cout << "\nEmployee 3: ";
            e3.printLastName()->printFirstName();

        cout << "\nEmployee 4: ";
            e4.printFirstName().printLastName();
        cout << "\nEmployee 4: ";
            e4.printLastName() -> printFirstName();
        cout << endl << endl;
    }
    cout << "\nNumber of employees after objects are deleted is " << " Number of employees = " << Employee :: getCount()
        <<" Male employees = " << Employee :: getmCount() << " Female employees "
        << Employee :: getfCount() <<  endl;
}

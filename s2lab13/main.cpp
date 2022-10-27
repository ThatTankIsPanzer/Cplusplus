#include <iostream>
#include <stdexcept>
#include <new>
#include "Array.h"
using namespace std;

int main()
{
    Array integers1(5);
    Array integers2;

    cout << "Enter 15 integers:" << endl;
    cin >> integers1 >> integers2;

    cout << "\nAfter input, the Arrays contain:\n"
    << "integers1: \n" << integers1
    << "integers2: \n" << integers2;

    cout << "\nEvaluating: integers1 != integers2" << endl;

    if (integers1 != integers2)
    cout << "integers1 and integers2 are not equal" << endl;

    const Array integers3( integers1 );
    cout << "\n\nAssigning integers2 to integers1" << endl;
    integers1 = integers2;

    cout << "integers1:\n" << integers1 << "integers2:\n" << integers2;

    cout << "Execute integers2 = integers2:" <<endl;
    integers2 = integers2;

    cout << "integers2[2] is " << integers2[2] << endl;
    try
    {
        cout << "integers3[25] is " << integers3[25] << endl;
    }
    catch(exception &)
    {
        cout << "Array reading is not done." << endl;
    }
    cout << "\n\nAssigning 1000 to integers1[8]" <<endl;
    integers1 [8] =1000;
    cout << "integers1:\n" << integers1;

    cout << "\n\nAttempt to assign 1000 to integers[23]" << endl;
    try
    {
        integers1[23] = 1000;
    }
    catch( exception & )
    {
        cout << "Array writing is not done.\n" << endl;
    }

    double *ptr[50];
    cout << "Memory allocation for creating large arrays. \n";
    try
    {

        for (int i=0; i<50; i++)
        {
            ptr[i] = new double [500000000];
            cout <<"ptr[" << i <<"] points to 500,000,000 new integers\n";
        }
    }
    catch( bad_alloc &memoryAllocationException )
    {
        cerr << "Memory allocation exception occurs: " << memoryAllocationException.what() << endl;
    }
}

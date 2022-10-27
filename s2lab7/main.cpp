#include <iostream>
#include <iomanip>

using namespace std;

class Array {
    friend ostream &operator<<(ostream &, const Array &);
    friend istream &operator>>(istream &, Array &);
public:
    Array( int = 10 ); // default constructor
    Array( const Array & ); // copy constructor
    ~Array(); // destructor
    int getSize() const; // return size
    const Array &operator=( const Array & ); // assignment operator
    bool operator==( const Array & ) const; // equality operator
    // inequality operator; returns opposite of == operator
    bool operator!=( const Array &right ) const
        {
            return ! ( *this == right ); // invokes Array::operator==
        } // end function operator!=
    // subscript operator for non-const objects returns modifiable lvalue
    int &operator[]( int );
    // subscript operator for const objects returns rvalue
    int operator[]( int ) const;
    Array &operator-();
    Array operator+( Array & );
    Array &operator>>( int a );

private:
    int size; // pointer-based array size
    int *ptr; // pointer to first element of pointer-based array

}; // end class Array

Array :: Array(int arraySize)
{
    size = (arraySize > 0 ? arraySize : 10);
    ptr = new int [size];

    for (int i = 0; i < size; i++)
    {
        ptr[i] = 0;
    }
}

Array :: Array(const Array &arrayToCopy)
:size(arrayToCopy.size)
{
    ptr = new int [size];

    for (int i = 0; i < size; i++)
    {
        ptr[i] = arrayToCopy.ptr[i];
    }
}

Array :: ~Array()
{
    delete [] ptr;
}

int Array :: getSize() const
{
    return size;
}

const Array &Array :: operator = (const Array &right)
{
    if (&right != this)
    {
        if (size != right.size)
        {
            delete [] ptr;
            size = right.size;
            ptr = new int [size];
        }
    }
    for (int i = 0; i < size; i++)
    {
        ptr[i] = right.ptr[i];
    }
    return *this;
}

bool Array :: operator == (const Array &right) const
{
    if (size != right.size)
    {
        return false;
    }
    for (int i = 0; i < size; i++)
    {
        if (ptr[i] != right.ptr[i])
        {
            return false;
        }
    }
    return true;
}

int &Array :: operator[] (int subscript)
{
    if (subscript < 0 || subscript >= size)
    {
        cerr << "\nError: Subscript " << subscript << " out of range." << endl;
        exit(1);
    }
    return ptr[subscript];
}

ostream &operator<<( ostream &output, const Array &a )
{
    int i;
    // output private ptr-based array
    for ( i = 0; i < a.size; i++ )
    {
        output << setw( 12 ) << a.ptr[ i ];
        if ( ( i + 1 ) % 4 == 0 ) // 4 numbers per row of output
            output << endl;
    } // end for
    if ( i % 4 != 0 )  // end last line of output
        output << endl;
    return output;   // enables cout << x << y;
}

istream &operator>>( istream &input, Array &a )
{
    for ( int i = 0; i < a.size; i++ )
        input >> a.ptr[i];
    return input;   // enables cin >> x >> y;
}

Array &Array :: operator-()
{
    for ( int i = 0; i < size; i++ )
    {
        ptr[i] = -ptr[i];
    }

    return *this;
}

Array Array :: operator+( Array &a )
{
    Array big(a.size + size);

    for ( int i = 0; i < size; i++ )
    {
       big.ptr[i] = ptr[i];
    }

    for ( int i = 0; i < a.size; i++ )
    {
       big.ptr[i + size] = a.ptr[i];
    }
    //a+b
    return big;
}

Array &Array :: operator>>( int a)
{
    a = a % size;
    Array temp(size);


    for (int i = 0; i < size; i++)
    {
        temp.ptr[i] = ptr[i];
    }
    for (int i = 0; i < size; i++)
    {
        ptr[i+a] = temp[i];
    }
    for(int i = 0; i < a; i++)
    {
        ptr[i] = temp[size-a+i];
    }

    return *this;
}

int main()
{
    Array integers1(7);
    Array integers2;

    cout << "Size of Array integers1 is "
    << integers1.getSize()
    << "\nArray after initialization:\n" << integers1;

    cout << "\nSize of Array integers2 is "
    << integers2.getSize()
    << "\nArray after initialization:\n" << integers2;

    cout << "\nInput 17 integers: " << endl;
    cin >> integers1 >> integers2;

    cout << "After input, the Arrays contain:\n" << "integers1:\n" << integers1 << "integers2:\n" << integers2;

    cout << "\nEvaluating integers1 != integers2" << endl;
    if (integers1 != integers2)
    {
        cout << "integers1 and integers2 are not equal" << endl;
    }

    Array integers3(integers1);
    cout << "Size of Array integers3 is " << integers3.getSize() << "\nArray after initialization:\n" << integers3;

    cout << "\nAssign integers2 to integers1:" << endl;
    integers1 = integers2;
    cout << "integers1:\n" << integers1 << "\nintegers2: " << integers2;

    cout << "\nEvaluating integers1 == integers2" << endl;
    if (integers1 != integers2)
    {
        cout << "integers1 and integers2 are equal" << endl;
    }

    cout << "\nintegers1[5] is " << integers1[5];

    cout << "\n\nAssign 1000 to integers1[5]" << endl;
    integers1[5] = 1000;
    cout << "integers1:\n" << integers1;

///////////////////////////////////////////////////////////////////////////////////////////////////insert part
integers3 = -integers3;
cout << "integers2:\n" << integers2 << endl;
cout << "integers3:\n" << integers3 << endl;
Array C;
C = integers1 + integers2 + integers3;
cout << "C = integers1 + integers2 + integers3:\n" << C;
int k = 30;
C >> k;
cout << "shifting the elements of C to the right by " << k << "place:\n" << C;
///////////////////////////////////////////////////////////////////////////////////////////////////insert part
    cout << "\n\nAssign 1000 to integers1[15]" << endl;
    integers1[15] = 1000;
}


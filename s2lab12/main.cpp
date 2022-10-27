#include <iostream>
#include <iomanip>

using namespace std;

template <typename T>
class Array {
    template< typename U > friend ostream &operator<<(ostream &, const Array<U> &);
    template< typename U > friend istream &operator>>(istream &, Array<U> &);
public:
    Array( int = 10 ); // default constructor
    Array( const Array & ); // copy constructor
    ~Array(); // destructor
    int getSize() const; // return size
    const T &operator=( const Array & ); // assignment operator
    bool operator==( const Array & ) const; // equality operator
    // inequality operator; returns opposite of == operator
    bool operator!=( const Array &right ) const
        {
            return ! ( *this == right ); // invokes Array::operator==
        } // end function operator!=
    // subscript operator for non-const objects returns modifiable lvalue
    T &operator[]( int );
    // subscript operator for const objects returns rvalue
    T operator[]( int ) const;
    void swap(int a, int b);

private:
    int size; // pointer-based array size
    T *ptr; // pointer to first element of pointer-based array

}; // end class Array

template< typename T >
Array<T> :: Array(int arraySize)
{
    size = (arraySize > 0 ? arraySize : 10);
    ptr = new T [size];


}

template< typename T >
Array<T> :: Array(const Array &arrayToCopy)
:size(arrayToCopy.size)
{
    ptr = new T [size];

    for (int i = 0; i < size; i++)
    {
        ptr[i] = arrayToCopy.ptr[i];
    }
}

template< typename T >
Array<T> :: ~Array()
{
    delete [] ptr;
}

template< typename T >
int Array<T> :: getSize() const
{
    return size;
}

template< typename T >
const T &Array<T> :: operator = (const Array &right)
{
    if (&right != this)
    {
        if (size != right.size)
        {
            delete [] ptr;
            size = right.size;
            ptr = new T [size];
        }
    }
    for (int i = 0; i < size; i++)
    {
        ptr[i] = right.ptr[i];
    }
    return *this;
}

template< typename T >
bool Array<T> :: operator == (const Array<T> &right) const
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

template< typename T >
T &Array<T> :: operator[] (int subscript)
{
    if (subscript < 0 || subscript >= size)
    {
        cerr << "\nError: Subscript " << subscript << " out of range." << endl;
        exit(1);
    }
    return ptr[subscript];
}

template< typename T >
T Array<T> :: operator[] (int subscript) const
{
    if (subscript < 0 || subscript >= size)
    {
        cerr << "\nError: Subscript " << subscript << " out of range." << endl;
        exit(1);
    }
    return ptr[subscript];
}

template< typename T >
void Array<T> :: swap(int a, int b)
{
    if(a > size || b > size || a < 0 || b < 0)
    {
        cout << "**Error: swapping fails, subscript X is out of range." << endl;
    }
    else
    {
        T temp = ptr[a];
        ptr[a] = ptr[b];
        ptr[b] = temp;
    }
}

template< typename U >ostream &operator<<( ostream &output, const Array<U> &a )
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

template< typename U >istream &operator>>( istream &input, Array<U> &a )
{
    for ( int i = 0; i < a.size; i++ )
        input >> a.ptr[i];
    return input;   // enables cin >> x >> y;
}

int main()
{
    Array<int> integers1(5);
    Array<int> integers2;

    cout << "Enter 15 integers:" << endl;
    cin >> integers1 >> integers2;

    cout << "\nAfter input, the Arrays contain:\n" << "integers1:\n" << integers1 << "integers2:\n" << integers2;

    cout << "\nEvaluating: integers1 != integers2" << endl;

    if(integers1 != integers2)
    {
        cout << "integers1 and integers2 are not equal" << endl;
    }

    Array<double> double1(10);
    cout << "\nEnter double precision numbers:" << endl;
    cin >> double1;

    cout << "\nCreate double2 initialized with double1:" << endl;
    Array<double> double2(double1);

    cout << "double1:\n" << double1 << "double2:\n" << double2;

    cout << "\nEvaluating: double1 == double2" << endl;
    if(double1 == double2)
    {
        cout << "double1 and double2 are equal" << endl;
    }

    cout << "\nAssigning 100.01 to double1[5]" << endl;
    double1[5] = 100.01;
    cout << "double1:\n" << double1 << endl;
    double1.swap(11,0);
    double2.swap(-1,9);
    cout << "double1[2]: " << double1[2] << " double1[8]: "<< double1[8] << endl;
    double1.swap(2,8);
    cout << "After swapping: double1[2]: " << double1[2] << " double1[8]: "<< double1[8] << endl;

    Array<string> strA(4);
    cout << "\nEnter 4 strings:" << endl;
    cin >> strA;
    cout << "strA[1]: " << strA[1] << " strA[3]: "<< strA[3] << endl;
    strA.swap(1,3);
    cout << "After swapping: strA[1]: " << strA[1] << " strA[3]: "<< strA[3] << endl;

    cout << "\nAttempt to assign \"abcd\" to strA" << endl;
    strA[5] = "abcd";
}

//Fig 11.7: Array.cpp
//Array class member- and friend-function defini
#include <iostream>
#include <istream>
#include <iomanip>
#include <cstdlib> // exit function prototy
#include "Array.h" // Array class defini
using namespace std;

//default constructor for class Array (default size 10)
Array::Array( int arraySize )
{
    size = ( arraySize > 0 ? arraySize : 10 ); // validate arraySize
    ptr = new int[ size ]; // create space for pointer-based array

        for( int i = 0; i < size; i++ )
        {
            ptr[ i ]=0;// set pointer-based array element
        }

}// end Array default constructor

// copy constructor for class Array;
// must receive a reference to prevent infinite recursion
Array ::Array( const Array &arrayToCopy ) : size( arrayToCopy.size )
{
    ptr = new int[ size ]; // create space for pointer-based array

    for ( int i = 0; i < size; i++ )
        ptr [ i ] = arrayToCopy.ptr[i ]; // copy into object
}// end Array copy constructor

// destructor for class Array

Array ::~Array()
{
    delete [] ptr; // release pointer-based array space
}// end deconstructor

// overloaded assignment operator;
// const return avoids: ( a1 = a2 ) = a3

const Array  &Array::operator=(const Array &right )
{

    try
    {
        if ( &right == this )
        {
            throw exception();
        }

        if( size != right.size )
        {
            delete [] ptr;
            size = right.size;
            ptr = new int [size];
        }

        for (int i=0; i < size; i++)
        {
            ptr[ i ] = right.ptr[ i ];
        }
    }
    catch( exception &)
    {
        cout << "\nARRAYS TRIES TO ASSIGN TO ITSELF!!\n" << endl;
    }

    return *this;
}



bool Array::operator==( const Array &right) const
{
    if(size != right.size)
    {
        return false;
    }

    for(int i=0; i < size; i++)
    {
        if(ptr[ i ] != right.ptr[ i ])
        {
            return false;
        }
    }

    return true;
}



int &Array::operator[](int subscript)
{
    try
    {

        if( subscript < 0 || subscript >= size)
        {
            throw exception();
        }
        return ptr[subscript];

    }
    catch( exception & )
    {
        cout << "Bad array index (left value): " << subscript << endl;
        throw exception();
    }
}


int Array::operator[]( int subscript ) const
{
    try
    {
        if( subscript < 0 || subscript >= size)
        {
            throw exception();
        }
        return ptr[subscript];
    }
    catch( exception & )
    {
        cout << "Bad array index (right value): " << subscript << endl;
        throw exception();
    }
}



istream &operator>> ( istream &input, Array &a)
{
     for( int i=0; i < a.size; i++)
     {
        input >> a.ptr[ i ];
     }
     return input;
}


ostream &operator<<( ostream &output, const Array &a)
{
    int i;
    for ( i = 0; i < a.size; i++ )
    {
        output << setw( 12 ) << a.ptr[ i ];

        if ( ( i +1 ) % 4 == 0 )
            output << endl;
    }

    if( i % 4 != 0 )
        output << endl;

    return output;
}






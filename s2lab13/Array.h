// Fig. 11.6: Array.h
// Array class definition with overloaded operators.
#ifndef ARRAY_H
#define ARRAY_H
#include <iostream>
using namespace std;

class Array{
friend ostream &operator<<( ostream &, const Array & );
friend istream &operator>>( istream &, Array & );
public:
    Array( int = 10 ); // default constructor
    Array( const Array & ); // copy constructor
    ~Array();// destructor

    const Array &operator=( const Array & ); // assignment operator
    bool operator==( const Array &) const; // equality o

    //inequality operator; returns opposite of ==op
    bool operator!=( const Array &right ) const
    {
        return ! ( *this == right ); // invokes Array::operator==
    } // end function operator!=

    // subcript operator for non-const objects returns modifiabl
    int &operator[]( int );

    // subscript operator for const objects returns rvalue
    int operator[]( int ) const;


private:
    int size; // pointer-based array size
    int *ptr; // pointer to first element of pointer-base
}; // end class Array
#endif


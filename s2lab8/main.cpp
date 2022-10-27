#include <iostream>
#include <string>
#include <cctype>

using namespace std;

class HugeInt
{
    friend ostream &operator<< ( ostream &, const HugeInt & );
    friend HugeInt operator+ ( int, HugeInt );
    friend bool operator>=(const string &, const HugeInt &);
    friend bool operator>=(const int &, const HugeInt &);
public:
    static const int digits = 30;
    HugeInt ( long = 0 );
    HugeInt ( const string & );
    HugeInt operator+ ( const HugeInt & ) const;
    HugeInt operator+ ( int ) const;
    HugeInt operator+ ( const string & ) const;
    HugeInt operator++ ();
    HugeInt operator++ ( int );
    bool operator>=(const HugeInt &op2);
    bool operator>=(const string &);

private:
    short integer[digits];

};

HugeInt :: HugeInt  ( long value )
{
    for (int i = 0; i < digits; i++)
    {
        integer[i] = 0;
    }

    for (int j = digits - 1; value != 0 && j >= 0; j--)
    {
        integer[j] = value % 10;
        value /= 10;
    }
}

HugeInt :: HugeInt ( const string &number )
{
    for (int i = 0; i < digits; i++)
    {
        integer[i] = 0;
    }

    int length = number.size();

    for (int j = digits - length, k = 0; j < digits; j++, k++)
        if (isdigit( number[k] ))
        {
            integer[j] = number[k] - '0';
        }
}

HugeInt HugeInt :: operator+ ( const HugeInt &op2 ) const
{
    HugeInt temp;
    int carry = 0;

    for (int i = digits - 1; i >= 0; i--)
    {
        temp.integer[i] = integer[i] + op2.integer[i] + carry;
       // cout << temp.integer[i] << endl;
        if (temp.integer[i] > 9)
        {
            temp.integer[i] %= 10;
            carry = 1;
        }
        else
        {
            carry = 0;
        }
    }
    return temp;
}

HugeInt HugeInt :: operator+ ( int op2 ) const
{
    return *this + HugeInt (op2);
}

HugeInt HugeInt :: operator+ ( const string &op2 ) const
{
    return *this + HugeInt (op2);
}

ostream &operator<<( ostream &output, const HugeInt &num )
{
    int i;
    for ( i = 0; (num.integer[i] == 0) && (i <= HugeInt::digits); i++ )
        ;

    if (i == HugeInt::digits)
    {
        output << 0;
    }
    else
    {
        for ( ; i < HugeInt::digits; i++)
        {
            output << num.integer[i];
        }
    }

    return output;
}

HugeInt operator+ (int op, HugeInt op2)
{
    return HugeInt(op) + op2;
}

HugeInt operator+ (string op, HugeInt op2)
{
    return HugeInt(op) + op2;
}

HugeInt HugeInt :: operator++ ( int )
{
    HugeInt op = *this;
    *this = *this + HugeInt(1);
    return op;
}
HugeInt HugeInt :: operator++ ()
{
    *this = *this + 1;
    return *this ;
}

bool HugeInt::operator>=(const HugeInt &op2)
{
    for (int i = 0; i < digits; i++)
    {
        if(integer[i] != op2.integer[i])
        {
            //cout << i << " " << integer[i] << " " << op2.integer[i];
            if (integer[i] > op2.integer[i])
            {
                return true;
            }
            else
            {
                return false;
            }
        }
    }
}

bool HugeInt::operator>=(const string &op2)
{
    HugeInt op(op2);
    for (int i = 0; i < digits; i++)
    {
        if(integer[i] != op.integer[i])
        {
            //cout << i << " " << op.integer[i] << " " << op2.integer[i];
            if (integer[i] > op.integer[i])
            {
                return true;
            }
            else
            {
                return false;
            }
        }
    }
}

bool operator>=(const string &op1, const HugeInt &op2)
{
    HugeInt op(op1);
    for (int i = 0; i < 30; i++)
    {
        if(op.integer[i] != op2.integer[i])
        {
            //cout << i << " " << op.integer[i] << " " << op2.integer[i];
            if (op.integer[i] > op2.integer[i])
            {
                return true;
            }
            else
            {
                return false;
            }
        }
    }
}

bool operator>=(const int &op1, const HugeInt &op2)
{
    HugeInt op(op1);
    for (int i = 0; i < 30; i++)
    {
        if(op.integer[i] != op2.integer[i])
        {
            //cout << i << " " << op.integer[i] << " " << op2.integer[i];
            if (op.integer[i] > op2.integer[i])
            {
                return true;
            }
            else
            {
                return false;
            }
        }
    }
}

int main()
{
    HugeInt n1(7654321);
    HugeInt n2(7891234);////origin
    HugeInt n3("99999999999999999999999999999");
    HugeInt n4("1");
    //HugeInt n5;///////origin
    HugeInt n5(n4);////////new
    //cout << "n1 is "<< n1 << "\nn2 is "<< n2  << "\nn3 is "<< n3 << "\nn4 is "<< n4 << "\nn5 is "<< n5 << "\n\n"; ////origin

    /////////////////////////////////////////////////////////////////////////////////////////new
    cout << "n1 is "<< n1 << "\nn3 is "<< n3 << "\nn4 is "<< n4 << "\nn5 is "<< n5 << "\n\n";
    HugeInt n6 = n3 + n4;

    cout << "n6 = " << n3 << " + " << n4 << " = " << n6 << "\n\n";
    cout << "9 + n1 = " << 9 + n1 << " " << "9" + n1 << " " << n1 + 9 << endl;
    cout << "n4 + 100 + 900 + n5= " << n4 + 100 + "900" + n5 << endl;
    cout << "n3++ = " << n3++ << endl;
    cout << "3n = " << n3 << endl;
    cout << "++n3 = " << ++n3 << endl;
    cout << "3n = " << n3 << endl;

    if (n3 >= n1)
        cout << "\nyes-1" << endl;
    else cout << "\nno-1" << endl;

    if (n3 >= 100)
        cout << "\nyes-2" << endl;
    else cout << "\nno-2" << endl;

    if (100 >= n3)
        cout << "\nyes-3" << endl;
    else cout << "\nno-3" << endl;

    if (n3 >= "100")
        cout << "\nyes-4" << endl;
    else cout << "\nno-4" << endl;

    if ("100" >= n3)
        cout << "\nyes-5" << endl;
    else cout << "\nno-5" << endl;
    ///////////////////////////////////////////////////////////////////new
    //////////////////////////////////////////////////////////////origin
    /*n5 = n1 + n2;
    cout << n1 << " + " << n2 << " = " << n5 << "\n\n";

    cout << n3 << " + " << n4 << " = " << (n3 + n4) << "\n\n";

    n5 = n1 + 9;
    cout << n1 << " + " << "9" << " = " << n5 << "\n\n";

    n5 = n2 + "10000";
    cout << n2 << " + " << "10000" << " = " << n5 << "\n\n";*/
    //////////////////////////////////////////////////////////////origin
}

#include <iostream>
#include <string>
using namespace std;

class Stack
{
    private:
        int stackSize; // size of a stack
        int stackPtr; // the number of characters stored in the stack. It should be also used as an
        // index into a stack entry where the top most element is located in the stack.
        char *charStack; // a character pointer that points a character array which should be
        // created dynamically using new statement.
    public:
        Stack(int = 1, int = 0, char * = NULL);
        // constructor with an argument that will be used to initialize the stack with a given size.
        // When a stack is initially created, the private data members should be initialized.
        void push(char); // Push a character onto the top of a stack.
        char pop(); // Return the topmost element from a stack
        void reset(); // Reset stackPtr to 0. This says that the stack is reset.
        bool empty(); // Return true if a stack is empty
        bool full(); // Return true if a stack is full
};

Stack::Stack(int newSize, int newPtr, char *newStack)
{
    stackSize = newSize;
    stackPtr = newPtr;
    charStack = new char[stackSize];
}

void Stack::push(char i)
{
    charStack[stackPtr] = i;
    stackPtr++;
}

char Stack::pop()
{
    stackPtr--;
    return charStack[stackPtr];
}

void Stack::reset()
{
    stackPtr = 0;
}

bool Stack::empty()
{
    if(stackPtr == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool Stack::full()
{
    if(stackPtr == stackSize)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void checkExpression(string data, Stack &aStack)
{
    for(int i = 0; i < data.size(); i++)
    {
        if(data[i] == '(')
        {
            if(aStack.full())
            {
                cout << "stack full" << endl;
                aStack.reset();
                return;
            }
            aStack.push(data[i]);
        }
        if(data[i] == ')')
        {
            if(aStack.empty())
            {
                cout << "more )'s" << endl;
                aStack.reset();
                return;
            }
            aStack.pop();
        }
    }
    if(aStack.empty())
    {
        cout << "Correct" << endl;
        aStack.reset();
        return;
    }
    else
    {
        cout << "more ('s" << endl;
    }
        aStack.reset();

}

int main()
{
    int Size;
    int tc;    //testcase
    string data = "";
    cin >> Size;
    cin >> tc;
    Stack aString(Size, 0, NULL);
    for(int i = 0; i < tc; i++)
    {
        cin >> data;
        checkExpression(data, aString);
    }
}


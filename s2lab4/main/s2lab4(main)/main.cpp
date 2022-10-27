#include <iostream>
#include "Queue.h"
using namespace std;

int main()
{
    int aSize;
    int tc;
    int time = 0;
    int num;
    int myTestNum;
    int idealTestNum;

    cin >> aSize;
    cin >> tc;

    Queue aQueue1(aSize);
    Queue aQueue2(aSize);

    for(int i = 0; i < tc; i++)
    {
        time=0;
        cout << "test " << i+1 << ":" << endl;
        cin >> num;

        for(int j = 0; j < num; j++)
        {
            cin >> myTestNum;
            aQueue2.enqueue(myTestNum);
        }
        for(int j = 0; j < num; j++)
        {
            cin >> idealTestNum;
            aQueue1.enqueue(idealTestNum);
        }

        while(!aQueue1.isEmpty())
        {
            if(aQueue1.peek() == aQueue2.peek())
            {
                aQueue1.dequeue();
                aQueue2.dequeue();
                time= time + 2;
            }
            if(aQueue1.peek() != aQueue2.peek())
            {
                aQueue1.enqueue(aQueue1.dequeue());
                aQueue1.printQueue();
                time++;
            }
        }
            cout << time <<endl;
            aQueue1.clearQueue();
            aQueue2.clearQueue();
    }

}

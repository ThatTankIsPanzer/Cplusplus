#include <iostream>
#include "Queue.h"

using namespace std;

Queue :: Queue(int QSize)
{
    size = QSize;
    rear = -1;
    front = 0;
    count = 0;
    intQueue = new int[size];
    cout << "A queue of size " << size << " is created." << endl;
}

Queue :: ~Queue()
{
    cout << "A queue of size " << size << " is destroyed." << endl;
}

void Queue :: enqueue(int integer)
{
    intQueue[rear+1] = integer;
    count++;
    rear++;
}

Queue :: dequeue()
{
    int temp;
    temp = intQueue[0];
    for(int i = 0; i < count-1; i++)
    {
        intQueue[i] = intQueue[i+1];
    }
    count--;
    rear--;
    return temp;
}

Queue :: peek()
{
    return intQueue[front];
}

Queue :: getCount()
{
    return count;
}

Queue :: getSize()
{
    return size;
}

bool Queue :: isEmpty()
{
    if(count == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool Queue :: isFull()
{
    if(count == size)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void Queue :: clearQueue()
{
    delete []intQueue;
    rear = -1;
    front = 0;
    count = 0;
    intQueue = new int[size];
}

void Queue :: printQueue()
{
    for(int i = 0; i < count; i++)
    {
        cout << intQueue[i];
    }
    cout << endl;
}


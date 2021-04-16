#include "Vector.h"
#include "Queue.h"
#include <iostream>
using namespace std;

Queue::Queue(int s)
{
    maxSize = 30;
    queue = new int[maxSize];
    head = 0;
    tail = -1;
    current = 0;
}

void Queue::push(int number)
{
    if (tail == maxSize - 1)
    {
        tail = -1;
        current = 0;
    }
    queue[++tail] = number;
    current++;
}

int Queue::pop()
{
    int head_n = queue[head++];
    if (head == maxSize)
        head = 0;
    current--;
    return head_n;
}

int Queue::front()
{
    return queue[head];
}

bool Queue::empty()
{
    return(current == 0);
}

bool Queue::full()
{
    return(current == maxSize);
}

int Queue::size()
{
    return current;
}

void Queue::display()
{
    if (current == 0)
    {
        cout << "Очередь пуста \n";
        return;
    }

    if (head > tail)
    {
        int j = head;
        while (j != maxSize)
        {
            cout << queue[j] << endl;
            j++;
        }
        j = 0;
        while (j <= tail)
        {
            cout << queue[j] << endl;
            j++;
        }
    }
    else if (head < tail)
    {
        for (int i = head; i <= tail; i++)
        {
            if (i % 3 == 0)
                cout << "(" << queue[i] << ", ";
            else if (i % 3 == 1)
                cout << queue[i] << ", ";
            else
                cout << queue[i] << ")" << endl;
        }
    }
    else if (current == 1)
        cout << " " << queue[head];
}
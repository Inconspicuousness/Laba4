#ifndef QUEUE_H
#define QUEUE_H
#include <iostream>
using namespace std;
class Queue
{
private:
    int maxSize;
    int* queue;
    int head;
    int tail;
    int current;
public:
    Queue(int s);
    void push(int number);
    int pop();
    int front();
    bool empty();
    bool full();
    int size();
    void display();

};
#endif

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

#ifndef VECTOR_H
#define VECTOR_H
#include <iostream>
using namespace std;

template<typename V>
class Vector
{
protected:
    V* vector;
    int size;
public:
    Vector();
    ~Vector();
    void fillVector(int s);
    Vector(int s);
    void printVector();
};
#endif
    #include "Vector.h"
#include <iostream>
using namespace std;

template<typename V> Vector<V>::Vector() {}
template<typename V> Vector<V>::~Vector()
{
    delete[] vector;
}
template<typename V> Vector<V>::Vector(int s)
{
    size = s;
    vector = new V[size];
}


template<typename V>void Vector<V>::printVector()
{
    for (int i = 0; i < size; i++)
    {
        cout << vector[i] << " ";
    }
}

template<typename V>void Vector<V>::fillVector(int s)
{
    size = s;
    for (int i = 0; i < size; i++)
    {
        vector[i] = rand() % 10;
    }
}

#include "Vector.h"
#include "Queue.h"
#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");
    int number = 30;
    Queue queue_vectors(number);

    int vectors[10][3] = { 1, 4, 7,
                          2, 5, 8,
                          3, 6, 9,
                          13, 45, 7,
                          0, 5, 0,
                          3, 6, 3,
                          11, 4, 2,
                          2, 95, 48,
                          3, 2, 6,
                          0, 4, 8 };
    const int& head = vectors[0][0];
    const int& tail = vectors[9][2];
    for (int i = 0; i < 10; i++)
        for (int j = 0; j < 3; j++)
        {
            queue_vectors.push(vectors[i][j]);
        }

    cout << "Изначальная очередь:\n";
    queue_vectors.display();

    Queue vectors_even(number);
    Queue vectors_odd(number);

    int a = 0;
    for (int i = 0; i < 10; i++)
    {
        a == 0;
        for (int j = 0; j < 3; j++)
        {
            a = (vectors[i][0] * vectors[i][0] + vectors[i][1] * vectors[i][1] + vectors[i][2] * vectors[i][2]);
            int b = sqrt(a);
            if (b % 2 == 0)
            {
                vectors_even.push(vectors[i][j]);
            }
            else
            {
                vectors_odd.push(vectors[i][j]);
            }
        }
    }
    cout << endl << "Начало очереди: " << head << "\nКонец очереди: " << tail << endl;


    cout << endl << "Векторы, длина которых чётна: \n";
    vectors_even.display();
    cout << endl << "Векторы, длина которых нечётна: \n";
    vectors_odd.display();

    return 0;
}


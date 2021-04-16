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




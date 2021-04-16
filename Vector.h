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
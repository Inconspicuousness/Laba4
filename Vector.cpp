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
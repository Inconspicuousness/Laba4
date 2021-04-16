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

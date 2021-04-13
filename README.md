#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;


int main()
{
    setlocale(LC_ALL, "Russian");

    vector < vector <int> > ivector = {{1, 4, 7},
                                       {2, 5, 8},
                                       {3, 6, 9},
                                       {13, 45, 7},
                                       {0, 5, 0},
                                       {3, 6, 3},
                                       {11, 4, 2},
                                       {2, 95, 48},
                                       {3, 2, 6},
                                       {0, 4, 8}};

    queue<int> queue_vectors;
    queue<int> vectors_even;
    queue<int> vectors_odd;
    const int& start = ivector[0][0];
    const int& end = ivector[9][2];


    for (int i = 0; i < ivector.size(); i++)
        for (int j = 0; j < ivector[i].size(); j++)
        {
          queue_vectors.push(ivector[i][j]);
        }

    cout << "Исходная очередь: \n";
    while (!queue_vectors.empty())
    {
        for (int i = 0; i < 3; i++)
        { 
            if (i == 0)
            {
                cout << "("  << queue_vectors.front() << ", ";
                queue_vectors.pop();
            }
            else if (i == 2)
            {
                cout << queue_vectors.front() << ") " << endl;
                queue_vectors.pop();
            }
            else
            {
                cout << queue_vectors.front() << ", ";
                queue_vectors.pop();
            }
        }
    }
 
    int a = 0;
    for (int i = 0; i < ivector.size(); i++)
    {
        a == 0;
        for (int j = 0; j < ivector[i].size(); j++)
        {
            a = (ivector[i][0] * ivector[i][0]+ ivector[i][1]*ivector[i][1] + ivector[i][2]*ivector[i][2]);
            int b = sqrt(a);
            if (b % 2 == 0)
            {
                vectors_even.push(ivector[i][j]);
            }
            else
            {
                vectors_odd.push(ivector[i][j]);
            }
        }
    }


    cout << endl << "Начало очереди: " << start << "\nКонец очереди: " << end << endl ;



    cout << endl << "Векторы, длина которых чётна: \n";

    while (!vectors_even.empty())
    {
        for (int i = 0; i < 3; i++)
        {
            if (i == 0)
            {
                cout << "(" << vectors_even.front() << ", ";
                vectors_even.pop();
            }
            else if (i == 2)
            {
                cout << vectors_even.front() << ") " << endl;
                vectors_even.pop();
            }
            else
            {
                cout << vectors_even.front() << ", ";
                vectors_even.pop();
            }
        }
    }

    cout << "Векторы, длина которых нечётна: \n";

    while (!vectors_odd.empty())
    {
        for (int i = 0; i < 3; i++)
        {
            if (i == 0)
            {
                cout << "(" << vectors_odd.front() << ", ";
                vectors_odd.pop();
            }
            else if (i == 2)
            {
                cout << vectors_odd.front() << ") " << endl;
                vectors_odd.pop();
            }
            else
            {
                cout << vectors_odd.front() << ", ";
                vectors_odd.pop();
            }
        }
    }

    return 0;
}

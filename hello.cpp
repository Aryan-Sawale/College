#include <bits/stdc++.h>
using namespace std;

template <typename T>
class vectorClass
{
public:
    T *arr;
    int capacity;
    int current;

    vectorClass()
    {
        arr = new T[1];
        capacity = 1;
        current = 0;
    }

    void push(T data)
    {
        if (current == capacity)
        {
            T *temp = new T[2 * capacity];

            for (int i = 0; i < capacity; i++)
            {
                temp[i] = arr[i];
            }

            delete[] arr;
            capacity *= 2;
            arr = temp;
        }

        arr[current] = data;
        current++;
    }

    void pop() { current--; }

    void print()
    {
        for (int i = 0; i < current; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main()
{
    vectorClass<int> v;
    v.push(10);
    v.push(20);
    v.push(30);
    v.push(40);
    v.pop();

    cout << "Vector elements : ";
    v.print();

    return 0;
}
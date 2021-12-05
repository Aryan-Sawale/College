#include <bits/stdc++.h>

using namespace std;

template <class T>
void Swap(T &a, T &b)
{
    a = a + b;
    b = a - b;
    a = a - b;
}

int main()
{
    int a = 5, b = 10;
    cout << "a before: " << a << endl;
    cout << "b before: " << b << endl;
    Swap(a, b);
    cout << "a after: " << a << endl;
    cout << "b after: " << b << endl;
}
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int age;
    cout<<"Enter age: ";
    cin>>age;

    try
    {
        if (age < 18)
        {
            throw age;
        }
        else
        {
            cout<<"Valid age\n";
        }
    }

    catch (int i)
    {
        cout<<"Invalid age\n";
    }
}
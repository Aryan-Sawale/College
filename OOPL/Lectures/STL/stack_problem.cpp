#include <bits/stdc++.h>

using namespace std;

int main()
{
    stack<int> s;
    s.push(8);
    s.push(5);
    s.push(6);

    try
    {
        if (s.empty())
            throw 1;

        cout << "element: " << s.top();
        s.pop();
    }

    catch (int i)
    {
        cout << "\nerror: stack is empty";
        exit(0);
    }
}
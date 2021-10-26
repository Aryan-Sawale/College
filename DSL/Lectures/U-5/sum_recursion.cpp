#include <bits/stdc++.h>

using namespace std;

int Sum(int n)
{
    if (n > 0)
        return n + Sum(n-1);
}

int main()
{
    int kek;
    cout<<"Enter num: ";
    cin>>kek;
    cout<<Sum(kek);
}
#include <bits/stdc++.h>

using namespace std;

int main()
{
    vector<int> vec;
    int ele;
    cout<<"Enter elements and press N to stop\n";
    cout<<"Element: ";
    while (cin >> ele)
    {
        vec.push_back(ele);
        cout<<"Element: ";
    }
    cout<<"\n";
    sort(vec.begin(), vec.end());
    for (auto i : vec)
    {
        cout<<i<<" ";
    }
}
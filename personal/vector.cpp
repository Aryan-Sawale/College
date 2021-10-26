#include <bits/stdc++.h>

using namespace std;

void display(vector<int> v)
{
    for (int i = 0; i < v.size(); i++)
    {
        cout<<v[i]<<" ";
    }
}

int main()
{
    vector<int> vec1;
    int ele, size;
    cout<<"input size: ";
    cin>>size;
    for (int i = 0; i < size; i++)
    {
        cout<<"element "<<(i + 1)<<": ";
        cin>>ele;
        vec1.push_back(ele);
    }

    for (auto i : vec1)
    {
        cout<<i<<"\n";
    }

    //vector<int>::iterator ptr;
    //refer Harry's video and cppreference for more useful fuctions
}
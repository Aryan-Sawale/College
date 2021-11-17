#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void display(vector<int> &v)
{
    for (int i = 0; i < v.size(); i++)
    {
        cout<<v[i]<<" ";
    }
    cout<<"\n";
}

void get_data(vector<int> &v)
{
    int count;
    cout<<"Enter number of integers: ";
    cin>>count;
    for (int i = 0; i < count; i++)
    {
        int ele;
        cout<<"Element: ";
        cin>>ele;
        v.push_back(ele);
    }
    cout<<"\n";
}

int main()
{
    vector<int> vec;
    get_data(vec);
    display(vec);
}

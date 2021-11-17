#include <bits/stdc++.h>

using namespace std;

int main()
{
  list<int> kek;
  for (int i = 0; i < 10; i++)
  {
    kek.push_back(i*2);
  }

  for (auto it = kek.begin(); it != kek.end(); it++)
  {
    cout<<*it<<" ";
  }
  cout<<"\n";

  kek.pop_back();

  for (auto it = kek.begin(); it != kek.end(); it++)
  {
    cout<<*it<<" ";
  }
  cout<<"\n";

  kek.pop_front();

  for (auto it = kek.begin(); it != kek.end(); it++)
  {
    cout<<*it<<" ";
  }
  
}
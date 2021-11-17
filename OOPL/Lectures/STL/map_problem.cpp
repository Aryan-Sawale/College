/*
Write a program in C++ to use map associative container, the keys will be names of states and  the values will be the populations of the states
When the program runs the user is prompted to type the name of the state. The program then looks in a map using the state name as index and return the
population of the state.
*/
#include <bits/stdc++.h>

using namespace std;

int main()
{
    map<string, int> map1;
    map1.insert(pair<string, int>("Andhra Pradesh", 100000));
    map1.insert(pair<string, int>("Andaman Nicobar", 200000));
    map1.insert(pair<string, int>("Assam", 300000));
    map1.insert(pair<string, int>("Arunachal Pradesh", 300000));
    map1.insert(pair<string, int>("Delhi", 400000));

    string input;
    cout<<"Enter state: ";
    getline(cin, input);

    auto itr = map1.find(input);
    if (itr != map1.end())
        cout<<"Population: "<<itr -> second;
    else
        cout<<"State doesn't exist in database";
}
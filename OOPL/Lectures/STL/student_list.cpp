#include <iostream>
#include <bits/stdc++.h>
#include <list>
#include <iterator>
#include <algorithm>
using namespace std;

//code not working

class Student
{
public:
    string name;
    int rollno;
} s[5];

bool operator==(const Student &s1, const Student &s2) //== operator is overloaded so that std::find can use it
{
    return (s1.name == s2.name);
}

int main()
{
    for (int i = 0; i < 5; i++)
    {
        cout << "Name: ";
        cin >> s[i].name;
        cout << "Rollno: ";
        cout << s[i].rollno;
        cout << "\n";
    }

    list<Student> student_list{s[0], s[1], s[2], s[3], s[4]};

    string input;
    cout << "\nEnter the name of student you want to find: ";
    cin >> input;

    auto it = find(student_list.begin(), student_list.end(), input);
    cout << "\n";
    cout << "Student found: " << (*it).name << "\n";
    cout << "Rollno: " << (*it).rollno;
}
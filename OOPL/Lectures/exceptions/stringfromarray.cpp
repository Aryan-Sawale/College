//Search a particular employee from employee array if inputted string matches then print yes otherwise throw exception 
#include <bits/stdc++.h>
#include <exception>

using namespace std;

class MyException: public exception
{
    public:
        const char* what() const throw()
        {
            return "Error: Employee not found\n";
        }
};

int main()
{
    vector<string> employee;
    int count;
    cout<<"Enter number of employees: ";
    cin>>count;
    for (int i = 0; i < count; i++)
    {
        string name;
        cout<<"Name: ";
        cin>>name;
        employee.push_back(name);
    }

    string key;
    try
    {
		cout<<"Search Employee: ";
        cin>>key;
        bool flag = false;
        for (int i = 0; i < count; i++)
        {
            if (key == employee[i])
                flag = true;
                break;
        }

        if (!flag)
        {
            throw MyException();
        }
    }

    catch (MyException &e)
    {
        cout<<"inside custom\n";
        cout<<e.what()<<"\n";
    }

    catch (exception &e)
    {
        //code
    }
}
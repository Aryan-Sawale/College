#include <bits/stdc++.h>

using namespace std;

class user
{
    public:
        char vehicle;
        int salary, age;
        string city;

        void get_data();
};

void user::get_data()
{
    cout<<"Enter age: ";
    cin>>age;
    if ((age < 18) || (age > 55))
    {
        throw 1;
    }

    cout<<"Enter salary: ";
    cin>>salary;
    if ((salary < 50000) || (salary > 100000))
    {
        throw 2;
    }

    cout<<"Do you have a 4-wheeler(y/n)? ";
    cin>>vehicle;
    if (vehicle == 'n')
    {
        throw 3;
    }

    cout<<"Enter city: ";
    cin>>city;
    if ( !((city == "Pune") || (city == "Mumbai") || (city == "Bangalore") || (city == "Chennai")) )
    {
        throw 4;
    }
}

int main()
{
    user u;

    try
    {
        u.get_data();
    }

    catch (int i)
    {
        switch(i)
        {
            case 1:
                cout<<"\nInvalid...Please enter age between 18 - 55";
                break;
            
            case 2:
                cout<<"\nInvalid...Please enter salary between 50k - 100k";
                break;
            
            case 3:
                cout<<"\nUser doesn't have 4-wheeler";
                break;
            
            case 4:
                cout<<"\nInvalid city";
                break;
        }
    }
}
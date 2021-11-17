//create user defined exception to check if student is vaccinated or not, if he is not vaccinated generate an exception. If vaccinated 
//with one dose, take the next vaccination date for second dose
#include <bits/stdc++.h>
#include <exception>

using namespace std;

class MyException: public exception
{
    public:
        const char* what() const throw()
        {
            return "Exception: You are not vaccinated\n";
        }
};

int main()
{
    char vac1, vac2;
    string date;
    try
    {
        cout<<"Have you taken the first dose?(Y/N)\n";
        cin>>vac1;
        cout<<"Have you taken the second dose?(Y/N)\n";
        cin>>vac2;
        if ((vac1 == 'N') && (vac2 == 'N'))
            throw MyException();
        
        if ((vac1 == 'Y') && (vac2 == 'N'))
            throw 1;
        
        if ((vac1 == 'Y') && (vac2 == 'Y'))
            throw 2;

        if ( ((vac1 != 'Y') && (vac1 != 'N')) || ((vac2 != 'Y') && (vac2 != 'N')) )
            throw 3;
    }

    catch (MyException &e)
    {
        cout<<e.what()<<"\n";
    }

    catch (int i)
    {
        if (i == 1)
        {
            cout<<"Enter date for next vaccination: ";
            cin>>date;
            cout<<"Thank you! See you after "<<date<<"!\n";
        }

        if (i == 2)
            cout<<"Very good!\n";

        if (i == 3)
            cout<<"Wrong input :(\n";
    }
}
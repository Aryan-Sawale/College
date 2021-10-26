#include <bits/stdc++.h>
#include <exception>

using namespace std;

class MyException: public exception
{
    public:
        const char* what() const throw()
        {
            return "custom kekek";
        }
};

int main()
{
    int error;
    try
    {
        cout<<"Error input: ";
        cin>>error;
        if (error == 1)
            throw MyException();
        if (error == 2)
            throw logic_error("kek");
    }

    catch (MyException &e)
    {
        cout<<"inside custom\n";
        cout<<e.what()<<"\n";
    }

    catch (exception &e)
    {
        cout<<"Inside standard\n";
    }
}
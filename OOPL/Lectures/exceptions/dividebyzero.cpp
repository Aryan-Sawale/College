#include <bits/stdc++.h>
#include <exception>

using namespace std;

class MyException: public exception
{
    public:
        const char* what() const throw()
        {
            return "Error: Division by 0";
        }
};

int main()
{
    int dividend, divisor;
	cout<<"Enter dividend: ";
	cin>>dividend;
	cout<<"Enter divisor: ";
	cin>>divisor;
    try
    {
		if (divisor == 0)
			throw MyException();
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
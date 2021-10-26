#include <bits/stdc++.h>

using namespace std;

int main()
{
    int num;
	cout<<"Enter: ";
	cin>>num;

	try
	{
		if (num < 0)
		{
			throw num;
        }
        else
        {
            cout<<"Positive value\n";
        }
	}

	catch (int i)
	{
		cout<<"Exceptionr: "<<i<<" is a negative number\n";
	}

	cout<<"end of program\n";
}
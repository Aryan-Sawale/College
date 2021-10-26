#include <bits/stdc++.h>

using namespace std;

int main()
{
    int num;
	char check = 'a';
	cout<<"Enter: ";
	cin>>num;

	try
	{
		if (num < 0)
		{
			throw num;
		}

		throw check;
	}

	catch (int i)
	{
		cout<<"negative\n";
	}

	catch (...)
	{
		cout<<"korega defaulto\n";
	}

	cout<<"end of program\n";
}

// int main()   //doesn't work
// {
//     int number = 10, ans = 0, krk = 0;
//     try
//     {
//         ans = number/krk;
//         throw ans;
//     }
//     catch(int i)
//     {
//         cout<<"denominator can't be zero";
//     }
    
// }

// int main()
// {
//     int n1,n2,result;
//     cout<<"Enter 1st number: ";
//     cin>>n1;
//     cout<<"Enter 2nd number: ";
//     cin>>n2;

//     try
//     {
//         if (n2 == 0)
//             throw n2;
        
//         else
//         {
//             result = n1 / n2;
//             cout<<"\nThe result is:"<<result;
//         }

//     }
//     catch(int x)
//     {
//         cout<<"can't divide by: "<<x;
//     }

//     cout<<"\nEnd of program";
    
// }
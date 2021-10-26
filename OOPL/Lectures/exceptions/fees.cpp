#include <iostream>

using namespace std;

int main()
{
    //demonstration of rethrow
    char choice;
    int amt;
    cout<<"Do you want fees in installment? ";
    cin>>choice;

    try
    {
        try
        {
            if (choice == 'y')
            {
                cout<<"Enter amount: ";
                cin>>amt;
                throw amt;
            }
        }

        catch (int a)
        {
            if (a > 75)
            {
                cout<<"Class teacher approved: "<<a<<"percent fees\n";
            }
            else
            {
                throw a;
            }
        }
    }

    catch (int x)
    {
        cout<<"HOD approved: "<<x<<"percent fees\n";
    }
}
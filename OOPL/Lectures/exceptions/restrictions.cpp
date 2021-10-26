#include <bits/stdc++.h>

using namespace std;

void demo() throw(int, double)
{
    int a = 2;
    if (a == 1)
        throw a;   //throwing integer
        
    else if (a == 2)
        throw 'A'; //throwing char

    else if (a == 3)
        throw 4.5; //throwing float

}

int main()
{
    try
    {
        demo();
    }

    catch(int i)
    {
        cout<<"integer exception\n";
    }
    
    catch(char ch)
    {
        cout<<"char exception\n";
    }

    catch(double d)
    {
        cout<<"double/float exception\n";
    }
}
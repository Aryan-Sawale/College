#include <bits/stdc++.h>

using namespace std;

int main()
{
    int a = 2;
    try
    {
        if (a == 1)
            throw a;   //throwing integer
        
        if (a == 2)
            throw 'A'; //throwing char

        if (a == 3)
            throw 4.5; //throwing float
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
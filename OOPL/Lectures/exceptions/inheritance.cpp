#include <bits/stdc++.h>

using namespace std;

class Base{};

class Derived : public Base {};

int main()
{
    try
    {
        throw Derived();
    }
    catch(Base b)
    {
        cout<<"Base\n";
    }

    catch (Derived d)
    {
        cout<<"Derived\n";
    }
    
}

//Here only base will be executed therefore catch blocks with base type should be written after derived type
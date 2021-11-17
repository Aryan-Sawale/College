#include <bits/stdc++.h>

using namespace std;

class Trouble
{
    public:
        Trouble(const char* pStr = "There's a problem!") : pMessage(pStr) {}   //initializer list concept (Initializer List is used in initializing the data members of a class. The list of members to be initialized is indicated with constructor as a comma-separated list followed by a colon.)
        const char* what() const {return pMessage;}

    private:
        const char* pMessage;
};

int main()
{
   for (int i = 0; i < 2; i++)
   {
       try
       {
           if (i == 0)
               throw Trouble();
           else
                throw Trouble("Nobody knows the trouble I've seen..");
       }

       catch (const Trouble &t)
       {
            cout<<endl<<"Exception: "<<t.what();
       }
   }
   return 0;
}
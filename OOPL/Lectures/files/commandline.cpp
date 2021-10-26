#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
    cout<<"\nNumber of arguments are: "<<argc;
    cout<<"\nActual arguments are: \n";
    for (int i = 0; i < argc; i++)
    {
        cout<<argv[i]<<"\n";
    }
}

// ./commandline two three four
// char *argv[] is equivalent to char **argv   (arrays and pointers relationship)
// argv[0] contains path/name of program 
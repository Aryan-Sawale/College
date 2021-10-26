#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class student
{
    public:
        int rollno;
        string kek;
    
    void get_data()
    {
        cout<<"GETTING DATA...\n";
        cout<<"Rollno: ";
        cin>>rollno;
        cout<<"kek: ";
        cin>>kek;
        cout<<"\n";
    }

    void display()
    {
        cout<<"DISPLAYING DATA...\n";
        cout<<"rollno: "<<rollno<<"\n";
        cout<<"name: "<<kek<<"\n";
        cout<<"\n";
    }
}s, s1, s2;

int main()
{
    s1.get_data();
    s2.get_data();

    ofstream file_out("read_write.txt");
    file_out.write( (char*)&s1, sizeof(s1));
    file_out.write( (char*)&s2, sizeof(s2));
    file_out.close();

    ifstream file_in("read_write.txt");
    file_in.read( (char*)&s, sizeof(s));
    s.display();
    file_in.read( (char*)&s, sizeof(s));
    s.display();
    file_in.close();
}

/*
file.read ( (char *)&V , sizeof (V) );
file.Write ( (char *)&V , sizeof (V) );

These function take two arguments. The first is 
the address of the variable V , and the second is 
the length of that variable in bytes . The address 
of variable must be cast to type char * (i.e pointer 
to character type) .
*/
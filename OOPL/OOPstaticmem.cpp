#include <iostream>
using namespace std;

class student
{
    static int count;
public:
    int rollno;
    student(int x)
    {
        rollno = x;
        count += 1;
    }
    static void data()
    {
        cout<<"count:"<<count<<endl;
    }
    void display()
    {
        cout<<"Roll no:"<<rollno<<endl;
    }
};
int student::count;

int main()
{
    student st1(10), st2(20), st3(30);
    student::data();
    st1.display();
    st2.display();
    
    return 0;
}

//static member functions can only use static variables and need to be called by scope resolution :: as shown above

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
    void display()
    {
        cout<<"Roll no:"<<rollno<<endl;
        cout<<"count:"<<count<<endl;
    }
};
int student::count;

int main()
{
    student st1(10), st2(20), st3(30);
    
    st1.display();
    st2.display();
    
    cout<< "Hello world" << endl;
    return 0;
}
#include <bits/stdc++.h>

using namespace std;

class student
{
    public:
    string name;
    int rollno;
    string bld_group;
    string dob;
    string clas;
    string div;
    long int tel;
    static int counter;
    student()  //default constructor
    {
        rollno = 0;
        counter++;
    }
    student(int rollno)  //parameterized
    {
        this -> rollno = rollno;
        counter++;
    }
    student(student &obj) //copy constructor
    {
        rollno = obj.rollno;
        name = obj.name;
        bld_group = obj.bld_group;
        dob = obj.dob;
        clas = obj.clas;
        div = obj.div;
        tel = obj.tel;
        counter++;
    }
    ~student() //destructor
    {
        cout<<" Deleting objects"<<endl;
        counter--;
    }
    inline static void dis_counter()
    {
        cout<<"No. of objects in the program: "<<counter<<endl;
    }
    void addData();
    friend void display(student &obj);
};

void student::addData()
{
    cout<<"Enter rollno"<<endl;
    cin>>rollno;
    cout<<"Enter name"<<endl;
    cin>>name;
    cout<<"Enter Blood group"<<endl;
    cin>>bld_group;
    cout<<"Enter DOB"<<endl;
    cin>>dob;
    cout<<"Enter class"<<endl;
    cin>>clas;
    cout<<"Enter Division"<<endl;
    cin>>div;
}

void display(student &obj)
{
    cout<<"\t"<<obj.rollno;
    cout<<"\t"<<obj.name;
    cout<<"\t"<<obj.bld_group;
    cout<<"\t"<<obj.dob;
    cout<<"\t"<<obj.clas;
    cout<<"\t"<<obj.div<<endl;
}
int student::counter = 0; //static variable
int main()
{
    student s1; //default
    student s2(101); //parameterize

    s2.addData();
    student s3(s2); //copy constructor

    cout<<"\tRollno\tName\tBloodgroup\tDOB\tClass\tDiv \n";
    display(s2);
    display(s3);

    student::dis_counter();

    int n,i;
    student *s[50];
    cout<<"Enter number of students in class"<<endl;
    cin>>n;

    for(i = 0; i < n; i++)
    {
        s[i] = new student();
    }
    for(i = 0; i < n; i++)
    {
        s[i] -> addData();
    }

    cout<<"\tRollno\tName\tBloodgroup\tDOB\tClass\tDiv \n";
    for(i = 0; i < n; i++)
    {
        display(*s[i]);
    }
    student::dis_counter();

    for(i = 0; i < n; i++)
    {
        delete(s[i]);
    }
    student::dis_counter();
}
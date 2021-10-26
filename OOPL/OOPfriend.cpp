#include <iostream>
using namespace std;

class DB;
class DM
{
    float dist_meter;
    public:
    void get()
    {
        cout<<"Enter distance in meters and centimeters: "<<endl;
        cin>>dist_meter;
    }
    friend void addition(DM, DB);
};

class DB
{
    float dist_feet;
    public:
    void get()
    {
        cout<<"Enter distance in feet and inches: "<<endl;
        cin>>dist_feet;
    }
    friend void addition(DM, DB);
};

void addition(DM M, DB F)
{
    float converted_value = 0.304 * F.dist_feet;
    float result_meter = M.dist_meter + converted_value;
    float result_feet = 3.28 * result_meter;
    int choice;
    cout<<"Enter 1 for result in meters and 2 for inches: ";
    cin>>choice;
    if(choice == 1)
    {
        cout<<"result in meters and centimeters: "<<result_meter;
    }
    else
    {
        cout<<"result in feet and inches: "<<result_feet;
    }
}

int main()
{
    DM a;
    DB b;
    a.get();
    b.get();
    addition(a, b);
}
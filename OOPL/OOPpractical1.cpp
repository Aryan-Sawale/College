#include <iostream>
using namespace std;

void addition(int no1, int no2);
void sub(int no1, int no2);
void multi(int no1, int no2);
void divi(int no1, int no2);
int main()
{
    int no1,no2;
    cout<<"Enter no1: ";
    cin>>no1;
    cout<<"Enter no2: ";
    cin>>no2;
    addition(no1, no2);
    sub(no1, no2);
    multi(no1, no2);
    divi(no1, no2);
    return 0;
}
void addition(int no1, int no2)
{
    int ans;
    ans = no1 + no2;
    cout<<"Addition of 2 numbers is: "<<ans<<endl;
}
void sub(int no1, int no2)
{
    int ans;
    ans = no1 - no2;
    cout<<"Subtraction of 2 numbers is: "<<ans<<endl;
}
void multi(int no1, int no2)
{
    int ans;
    ans = no1 * no2;
    cout<<"Multiplication of 2 numbers is: "<<ans<<endl;
}
void divi(int no1, int no2)
{
    float ans;
    ans = (float)no1 / (float)no2;
    cout<<"Division of 2 numbers is: "<<ans<<endl;
}

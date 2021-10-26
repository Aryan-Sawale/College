#include <iostream>
using namespace std;

class calculator
{
    public:
    int no1, no2;
    calculator()
    {
        cout<<"Enter No1: ";
        cin>>no1;
        cout<<"Enter No2: ";
        cin>>no2;
    }
    void addition();
    void sub();
    void divi();
    void multi();
};
void calculator::addition()
{
    int ans;
    ans = no1 + no2;
    cout<<"Addition is: "<<ans<<endl;
}
void calculator::sub()
{
    int ans;
    ans = no1 - no2;
    cout<<"Subtraction is: "<<ans<<endl;
}
void calculator::divi()
{
    float ans;
    ans = (float)no1 / (float)no2;
    cout<<"Division is: "<<ans<<endl;
}
void calculator::multi()
{
    int ans;
    ans = no1 * no2;
    cout<<"Multiplication is: "<<ans<<endl;
}

int main()
{
    calculator calc;
    char choice;
    char input;
    do
    {
        cout<<"\nEnter your choice: \n + : Addition \n - : Sub \n * : Multi \n / : div"<<endl;
        cin>>choice;
    
        switch(choice)
        {
            case '+': calc.addition();
            break;
            case '-': calc.sub();
            break;
            case '/': calc.divi();
            break;
            case '*': calc.multi();
            break;
        }
        cout<<"Enter Y to continue"<<endl;
        cin>>input;
    }while(input == 'Y' || input == 'y');
    
    return 0;
}
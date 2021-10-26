#include <iostream>
using namespace std;

class complex
{
public:
    float real, img;
    complex()                              //constructor which initializes real and img at the time of object creation
    {
        real = 0;
        img = 0;
    }
    void get_data()
    {
        cout<<"\nEnter the real no: ";
        cin>>real;
        cout<<"Enter the img no: ";
        cin>>img;
    }
    void display_data()
    {
        cout<<"Complex no. is: "<<real<<"+"<<img<<"i"<<endl;
    }
complex operator +(complex);              //return_type operator +(class_name)
complex operator *(complex);
friend ostream &operator <<(ostream &, complex &);
friend istream &operator >>(istream &, complex &);
};

complex complex::operator +(complex obj)  //return_type class_name :: operator +(class_name obj)  [calling function using ::]
{
    complex temp;                         //temp = c3
    temp.real = real + obj.real;          //direct real and img = c1  
    temp.img = img + obj.img;             //obj.real and obj.img = c2              
    return temp;
}

complex complex::operator *(complex obj)  
{
    complex temp;                         
    temp.real = real*obj.real - img*obj.img;            
    temp.img = real*obj.img + img*obj.real;                       
    return temp;
}

ostream &operator <<(ostream &out, complex &obj)
{
    out<<obj.real<<"+";
    out<<obj.img<<"i";
    return out;
}

istream &operator >>(istream &in, complex &obj)
{
    cout<<"Enter real no: ";
    in>>obj.real;
    cout<<"Enter img no: ";
    in>>obj.img;
    return in;
}

int main()
{
    complex c1,c2,c3,c4;
    
    c1.get_data();
    c1.display_data();
    c2.get_data();
    c2.display_data();
    c3 = c1 + c2;
    cout<<"\nAddition: "<<endl;
    c3.display_data();
    c3 = c1 * c2;
    cout<<"\nMultiplication: "<<endl;
    c3.display_data();
    cout<<"\n << and >> operator: "<<endl;
    cin>>c4;
    cout<<c4;
    
    return 0;
}
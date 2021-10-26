#include <bits/stdc++.h>

using namespace std;

#define MAX 100

class Stack      //if you name it stack with small 's' it gives an ambiguity error (due to stack in STL)
{
    public:
        int a[MAX];
        int top;
        Stack ()    //constructor to set default value of top
        {
            top = -1;
        }
        void push (int key);
        void pop ();

};

void Stack::push (int key)
{
    if (top == (MAX - 1))    //if stack is full
    {
        cout<<"Overflow!\n";
        return;
    }

    top++;
    a[top] = key;
}

void Stack::pop ()
{
    if (top == -1)     //if stack is empty
    {
        cout<<"Underflow!\n";
        return;
    }

    int val = a[top];
    top--;
    cout<<val<<" Has been popped";

}

int main()
{
    //
}
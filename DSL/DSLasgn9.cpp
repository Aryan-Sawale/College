#include <bits/stdc++.h>

using namespace std;

#define MAX 100

class Stack      //if you name it stack with small 's' it gives an ambiguity error (due to stack in STL)
{
    public:
        char a[MAX];
        int top;
        Stack ()    //constructor to set default value of top
        {
            top = -1;
        }
        void push (char key);
        void pop ();
        char gettop();
        bool isfull();
        bool isempty();
};

void Stack::push (char key)
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

    char val = a[top];
    top--;
    // cout<<val<<" Has been popped\n";
}

char Stack::gettop()
{
    return a[top];
}

bool Stack::isfull()
{
    if (top == (MAX - 1))
        return true;
    else
        return false;
}

bool Stack::isempty()
{
    if (top == -1)
        return true;
    else
        return false;
}

int main()
{
    Stack S;
    string code;
    cout<<"Enter expression: \n";
    cin>>code;
    for (int i = 0; i < code.length(); i++)
    {
        if ( (code[i] == '(') || (code[i] == '{') || (code[i] == '[') )
        {
            S.push(code[i]);
        }

        if ( (S.gettop() == '(') && (code[i] == ')') )
        {
            S.pop();
        }

        if ( (S.gettop() == '{') && (code[i] == ')') )
        {
            S.pop();
        }

        if ( (S.gettop() == '[') && (code[i] == ']') )
        {
            S.pop();
        }
    }

    S.isempty() ? cout<<"Well formed\n" : cout<<"Not Well formed\n";
}
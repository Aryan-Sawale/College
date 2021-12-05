#include <bits/stdc++.h>
#include <cctype> //for isdigit() etc. aka <ctype.h>

using namespace std;

#define MAX 100

class Stack //if you name it stack with small 's' it gives an ambiguity error (due to stack in STL)
{
public:
    char a[MAX]; //char stack
    int b[MAX];  //int stack
    int top;
    Stack() //constructor to set default value of top
    {
        top = -1;
    }

    //char stack functions
    void push(char key);
    void pop();
    char gettop();
    bool isfull();
    bool isempty();

    //int stack functions
    void push_int(int key);
    int gettop_int();
};

void Stack::push(char key)
{
    if (top == (MAX - 1)) //if stack is full
    {
        cout << "Overflow!\n";
        return;
    }

    top++;
    a[top] = key;
}

void Stack::pop()
{
    if (top == -1) //if stack is empty
    {
        cout << "Underflow!\n";
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

int get_preced(char ch)
{
    if ((ch == '*') || (ch == '/'))
    {
        return 2;
    }

    if ((ch == '+') || (ch == '-'))
    {
        return 1;
    }

    return 0;
}

void infix_to_postfix(string infix, string &postfix)
{
    Stack s;
    int weight;
    char ch;
    int i = 0;
    int infix_size = infix.size(); //for efficiency

    while (i < infix_size)
    {
        ch = infix[i];
        if (ch == '(')
        {
            s.push(ch);
            i++;
            continue;
        }

        if (ch == ')') //if we see a closing parenthesis, pop of all the elements and append it to the postfix expression till we encounter an opening paranthesis
        {
            while ((!s.isempty()) && (s.gettop() != '('))
            {
                postfix.push_back(s.gettop());
                s.pop();
            }
            if (!s.isempty()) //pop off the opening parenthesis also
            {
                s.pop();
            }
            i++;
            continue;
        }

        weight = get_preced(ch);
        if (weight == 0) //operand will have weight 0, append it to postfix
        {
            postfix.push_back(ch);
        }
        else // if weight != 0, it's an operator
        {
            if (s.isempty()) //if stack is empty, simply push new operator to it
            {
                s.push(ch);
            }
            else
            {
                while ((!s.isempty()) && (s.gettop() != '(') && (weight <= get_preced(s.gettop()))) // if operators in stack >= scanned operator pop them all to postfix
                {
                    postfix.push_back(s.gettop());
                    s.pop();
                }
                s.push(ch); // push scanned operator to stack when no >= operators remain
            }
        }
        i++;
    }

    while (!s.isempty()) // pop remaning items on stack to postfix
    {
        postfix.push_back(s.gettop());
        s.pop();
    }
}

void Stack::push_int(int key)
{
    if (top == (MAX - 1)) //if stack is full
    {
        cout << "Overflow!\n";
        return;
    }

    top++;
    b[top] = key;
}

int Stack::gettop_int()
{
    return b[top];
}

int evaluate_postfix(string &postfix)
{
    Stack s;
    int i = 0;
    char ch;
    int postfix_size = postfix.size();

    while (i < postfix_size)
    {
        ch = postfix[i];

        if (isdigit(ch)) // push numbers on stack
        {
            s.push_int(ch - 48); // 0 is 48 in ASCII
            i++;
        }

        else // if operator is found, pop the 2 numbers on stack, evaluate and push the result
        {
            int val1 = s.gettop_int();
            s.pop();
            int val2 = s.gettop_int();
            s.pop();

            if (ch == '*')
            {
                s.push_int(val2 * val1);
            }
            if (ch == '/')
            {
                s.push_int(val2 / val1);
            }
            if (ch == '+')
            {
                s.push_int(val2 + val1);
            }
            if (ch == '-')
            {
                s.push_int(val2 - val1);
            }

            i++;
        }
    }
    return s.gettop_int();
}

int main()
{
    Stack S;
    string infix, postfix;
    cout << "Enter infix expression:\n";
    cin >> infix;

    infix_to_postfix(infix, postfix);
    cout << "\nPostfix expression:\n";
    cout << postfix;

    cout << "\n\nEvaluation:\n";
    cout << evaluate_postfix(postfix);
}
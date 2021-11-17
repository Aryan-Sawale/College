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
    int infix_size = infix.size();

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
		else  // if weight != 0, it's an operator
        {
			if (s.isempty())  //if stack is empty, simply push new operator to it
            {
				s.push(ch);
			}
			else 
            {
				while ( (!s.isempty()) && (s.gettop() != '(') && (weight <= get_preced(s.gettop())) ) // if operators in stack >= scanned operator pop them all to postfix
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

int main()
{
    Stack S;
    string infix, postfix;
    cout<<"Enter infix expression:\n";
    cin>>infix;
    
    infix_to_postfix(infix, postfix);
    cout<<"Postfix expression:\n";
    cout<<postfix;
}  
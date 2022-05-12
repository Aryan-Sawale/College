#include <iostream>
#include <stack>

#define MAX 100

using namespace std;

class node
{
public:
    node *left;
    node *right;
    char data;
    node(char key)
    {
        data = key;
        left = NULL;
        right = NULL;
    }
};

class Stack
{
public:
    node *arr[MAX];
    int top;
    Stack() // constructor to set default value of top
    {
        top = -1;
    }
    void push(node *new_node);
    void pop();
    node *gettop();
    bool isempty();
};

void Stack::push(node *new_node)
{
    if (top == (MAX - 1)) // if stack is full
    {
        cout << "Overflow!\n";
        return;
    }
    arr[++top] = new_node;
}

void Stack::pop()
{
    if (top == -1) // if stack is empty
    {
        cout << "Underflow!\n";
        return;
    }
    top--;
}

node *Stack::gettop()
{
    return arr[top];
}

bool Stack::isempty()
{
    return (top == -1);
}

node *construct_tree(string exp)
{
    // stack<node *> mystack;
    Stack mystack;

    int exp_length = exp.length();
    for (int i = (exp_length - 1); i >= 0; i--)
    {
        if ((exp[i] == '+') || (exp[i] == '-') || (exp[i] == '*') || (exp[i] == '/'))
        {
            node *op1 = mystack.gettop();
            mystack.pop();
            node *op2 = mystack.gettop();
            mystack.pop();
            node *new_root = new node(exp[i]);
            new_root->left = op1;
            new_root->right = op2;
            mystack.push(new_root);
        }
        else
        {
            node *new_node = new node(exp[i]);
            mystack.push(new_node);
        }
    }

    return mystack.gettop();
}

void display_postorder(node *root)
{
    if (root == NULL)
    {
        return;
    }

    display_postorder(root->left);
    display_postorder(root->right);
    cout << root->data << " ";
}

void display_inorder(node *root)
{
    if (root == NULL)
    {
        return;
    }

    display_inorder(root->left);
    cout << root->data << " ";
    display_inorder(root->right);
}

void delete_tree(node *root)
{
    if (root == NULL)
    {
        return;
    }

    delete_tree(root->left);
    delete_tree(root->right);
    delete root;
}

void iter_postorder(node *root)
{
    // stack<node *> stack_1;
    // stack<node *> stack_2;
    Stack stack_1;
    Stack stack_2;

    stack_1.push(root);
    while (!stack_1.isempty())
    {
        node *temp_node = stack_1.gettop();
        stack_1.pop();
        stack_2.push(temp_node);
        if (temp_node->left != NULL)
        {
            stack_1.push(temp_node->left);
        }
        if (temp_node->right != NULL)
        {
            stack_1.push(temp_node->right);
        }
    }

    while (!stack_2.isempty())
    {
        cout << stack_2.gettop()->data << " ";
        stack_2.pop();
    }
}

int main()
{
    string expression;
    expression = "+--A*BC/DEF";
    // cout << "Enter expression: ";
    // cin >> expression;

    node *test_root = construct_tree(expression);
    cout << "\nPostorder expression: ";
    display_postorder(test_root);
    cout << "\nInorder expression: ";
    display_inorder(test_root);

    cout << "\nNon recursive postorder : ";
    iter_postorder(test_root);

    delete_tree(test_root);
    cout << "\nTree deleted";
}

// int main()
// {
//     string expression;
//     expression = "+--A*BC/DEF";
//     // cout << "Enter expression: ";
//     // cin >> expression;

//     node *test_root = construct_tree(expression);
//     // cout << "\nPostorder expression: ";
//     // display_postorder(test_root);
//     // cout << "\nInorder expression: ";
//     // display_inorder(test_root);

//     cout << "\nNon recursive postorder : ";
//     iter_postorder(test_root);

//     delete_tree(test_root);
//     cout << "\nTree deleted";
// }

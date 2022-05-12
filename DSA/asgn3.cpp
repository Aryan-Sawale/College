#include <iostream>

using namespace std;

class Node
{
public:
    Node *left;
    Node *right;
    char data;
    Node(char key)
    {
        data = key;
        left = right = NULL;
    }

    Node()
    {
        data = '0';
        left = right = NULL;
    }
};

Node *insert(Node *root, char key)
{
    if (root == NULL)
    {
        return new Node(key);
    }

    if (key == root->data)
    {
        cout << "Repeated value";
        return root;
    }

    if (key < root->data)
    {
        root->left = insert(root->left, key);
    }

    if (key > root->data)
    {
        root->right = insert(root->right, key);
    }

    return root;
}

void display_inorder(Node *root)
{
    if (root == NULL)
    {
        return;
    }

    display_inorder(root->left);
    cout << root->data << " ";
    display_inorder(root->right);
}

bool search_val(Node *root, int key)
{
    if (root == NULL)
    {
        return false;
    }
    if (key == root->data)
    {
        return true;
    }
    if (key < root->data)
    {
        return search_val(root->left, key);
    }
    if (key > root->data)
    {
        return search_val(root->right, key);
    }
}

bool update_val(Node *root, char key)
{
    if (root == NULL)
    {
        return false;
    }
    if (key == root->data)
    {
        cout << "Enter new value: ";
        cin >> root->data;
        return true;
    }
    if (key < root->data)
    {
        return update_val(root->left, key);
    }
    if (key > root->data)
    {
        return update_val(root->right, key);
    }
}

int main()
{
    Node *test_root = NULL;
    char choice = 'N';
    while (choice == 'N' || choice == 'n')
    {
        char ele;
        cout << "Enter element: ";
        cin >> ele;
        test_root = insert(test_root, ele);

        cout << "Exit? Y/N: ";
        cin >> choice;
    }

    cout << "\nTree:\n";
    display_inorder(test_root);

    char new_val;
    cout << "\n\nEnter value to be updated: ";
    cin >> new_val;
    if (!update_val(test_root, new_val))
    {
        cout << "Value does not exist in dictionary\n";
    }

    display_inorder(test_root);
}
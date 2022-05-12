#include <iostream>

using namespace std;

class Node
{
public:
    Node *left;
    Node *right;
    int data;
    Node(int key)
    {
        data = key;
        left = right = NULL;
    }

    Node()
    {
        data = 0;
        left = right = NULL;
    }
};

Node *insert(Node *root, int key)
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

void find_min(Node *root)
{
    while (root->left != NULL)
    {
        root = root->left;
    }

    cout << "Minimum value: " << root->data;
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

void mirror(Node *root)
{
    if (root == NULL)
        return;
    else
    {
        mirror(root->left);
        mirror(root->right);

        Node *temp = root->left;
        root->left = root->right;
        root->right = temp;
    }
}

Node *clone_tree(Node *root)
{
    if (root == NULL)
        return root;
    else
    {
        Node *clone = new Node();
        clone->data = root->data;

        clone->left = clone_tree(root->left);
        clone->right = clone_tree(root->right);

        return clone;
    }
}

Node *clone_mirror(Node *root)
{
    Node *mirror_tree = clone_tree(root);
    mirror(mirror_tree);
    return mirror_tree;
}

int max_height(Node *root)
{
    if (root == NULL)
    {
        return -1;
    }
    else
    {
        int left_height = max_height(root->left);
        int right_height = max_height(root->left);

        if (left_height > right_height)
        {
            return (left_height + 1);
        }
        else
        {
            return (right_height + 1);
        }
    }
}

int main()
{
    Node *test_root = NULL;
    char choice = 'N';
    while (choice == 'N' || choice == 'n')
    {
        int ele;
        cout << "Enter element: ";
        cin >> ele;
        test_root = insert(test_root, ele);

        cout << "Exit? Y/N: ";
        cin >> choice;
    }

    cout << "\nTree:\n";
    display_inorder(test_root);
    cout << "\n";
    find_min(test_root);

    int user_key;
    cout << "\n\nEnter value to be searched: ";
    cin >> user_key;

    search_val(test_root, user_key) ? cout << "\nValue exists in the tree\n" : cout << "\nValue does not exist in the tree\n";

    Node *test_clone = clone_mirror(test_root);
    cout << "\nOriginal tree:\n";
    display_inorder(test_root);
    cout << "\nMirrored tree:\n";
    display_inorder(test_clone);
}

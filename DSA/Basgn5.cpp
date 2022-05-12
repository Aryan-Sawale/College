#include <iostream>
#include <cstdlib>
#include <string.h>
using namespace std;

class node
{
public:
    string label;
    int ch_count;
    node *child[10];
};

void create_tree(node *&root)
{
    int tbooks, tchapters, i, j, k;
    root = new node();
    cout << "Enter name of book: ";
    cin >> root->label;
    cout << "Enter no. of chapters in book: ";
    cin >> tchapters;
    root->ch_count = tchapters;
    for (i = 0; i < tchapters; i++)
    {
        root->child[i] = new node;
        cout << "\nEnter Chapter name: ";
        cin >> root->child[i]->label;
        cout << "Enter no. of sections in  Chapter " << root->child[i]->label << " : ";
        cin >> root->child[i]->ch_count;
        for (j = 0; j < root->child[i]->ch_count; j++)
        {
            root->child[i]->child[j] = new node;
            cout << "Enter Section " << j + 1 << " name: ";
            cin >> root->child[i]->child[j]->label;
        }
    }
}

void display(node *&root)
{
    int i, j, k, tchapters;
    if (root != NULL)
    {
        cout << "\n-----Book Hierarchy----\n";

        cout << "\n Book title : " << root->label;
        tchapters = root->ch_count;
        for (i = 0; i < tchapters; i++)
        {

            cout << "\n\n Chapter " << i + 1;
            cout << " " << root->child[i]->label;
            cout << "\n Sections";
            for (j = 0; j < root->child[i]->ch_count; j++)
            {
                cout << "\n  " << root->child[i]->child[j]->label;
            }
        }
    }
}

int main()
{
    node *root = NULL;
    create_tree(root);
    cout << "child: " << root->label;
    display(root);
}
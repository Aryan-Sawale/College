#include <bits/stdc++.h>

using namespace std;
struct Node
{
  int data;
  Node *next;
};
void insert_at_end(Node* &head)
{
  Node *newnode = new Node();
  newnode->data = 2;
  newnode->next = NULL;
  head->next = newnode;
}
int main()
{
  //code
  Node *head = new Node();
  head->data = 1;
  head->next = NULL;
  insert_at_end(head);
  Node *temp = head;
  while (temp!=NULL)
  {
    cout << temp->data << " ";
    temp = temp->next;
  }
}
#include <bits/stdc++.h>

using namespace std;

class node
{
    public:
        int prn;
        string name;
        node *next;
		node(int num, string nam) //constructor
		{
			prn = num;
			name = nam;
			next = NULL;
		}
};


void append(node **head_ref)  //insert at end
{
	string nam;
	int num;

	cout<<"\nEnter Name: ";
	cin>>nam;
	cout<<"Enter PRN: ";
	cin>>num;

	node *new_node = new node(num, nam);

	if (*head_ref == NULL)  //if list is empty
	{
		*head_ref = new_node;
		return;
	}

	node *last = *head_ref;
	while (last -> next != NULL)
	{
		last = last -> next;
	}

	last -> next = new_node;
}

void push(node **head_ref)   //insert at beginning
{
	string nam;
	int num;
	
	cout<<"\nEnter Name: ";
	cin>>nam;
	cout<<"Enter PRN: ";
	cin>>num;

	node *new_node = new node(num, nam);

	new_node -> next = *head_ref;
	*head_ref = new_node;
}

void insert_after(node **head_ref)  //insert after specific PRN
{
	string nam;
	int num, key;
	
	cout<<"\nEnter the PRN after which to insert the member: ";
	cin>>key;
	cout<<"Enter Name: ";
	cin>>nam;
	cout<<"Enter PRN: ";
	cin>>num;

	node *temp = *head_ref;
	bool flag = false;
	while (temp != NULL)
	{
		if (temp -> prn = key)
		{
			flag = true;
			break;
		}
		temp = temp -> next;
	}

	if (flag)
	{
		node *new_node = new node(num, nam);
		new_node -> next = temp -> next;
		temp -> next = new_node;
	}
	else
	{
		cout<<"PRN not found\n";
	}
}

void delete_list(node **head_ref)
{
	node *temp = *head_ref;
	while (temp != NULL)
	{
		node *prev = temp;
		temp = temp -> next;
		delete prev;
	}
}

void delete_node(node **head_ref, bool prez, bool secre)
{
	if ((!prez) && (!secre))
	{
		int key;
		
		cout<<"\nEnter the PRN of member to be deleted: ";
		cin>>key;

		node *temp = *head_ref;
		node *prev = *head_ref;
		bool flag = false;
		while (temp != NULL)
		{
			if (temp -> prn = key)
			{
				flag = true;
				break;
			}
			prev = temp;
			temp = temp -> next;
		}

		if (flag)
		{
			prev -> next = temp -> next;
			delete temp;
			cout<<"Member with PRN no. "<<key<<"has been deleted\n";
		}
		else
		{
			cout<<"PRN not found\n";
		}
	}
	else if (prez)
	{
		node *temp = *head_ref;
		*head_ref = (*head_ref) -> next;
		delete temp;

		cout<<"\nPresident has been deleted\n";
	}
	else if (secre)
	{
		node *temp = *head_ref;
		node *prev = *head_ref;
		while (temp -> next != NULL) 
		{
			prev = temp;
			temp = temp -> next;
		}
		
		delete temp;
		prev -> next = NULL;

		cout<<"\nSecretary has been deleted\n";
	}
}

void display_list(node **head_ref)
{
	cout<<"\n";
	node *temp = *head_ref;

	if (temp == NULL)
	{
		cout<<"List is empty";
		return;
	}
	while (temp != NULL)
	{
		cout<<"Name: "<<temp -> name<<"   "<<"PRN: "<<temp -> prn<<"\n";
		temp = temp -> next;
	}
}

void display_count(node **head_ref)
{
	node *temp = *head_ref;
	int counter = 0;
	while (temp != NULL)
	{
		counter++;
		temp = temp -> next;
	}
	cout<<"\nThe number of members is: "<<counter;
}

void concatenate(node **head_ref1, node **head_ref2)
{
	node *last1 = *head_ref1;
	while (last1 -> next != NULL)
	{
		last1 = last1 -> next;
	}

	last1 -> next = *head_ref2;
	cout<<"\nLists have been concatenated\n";
}

int main()
{
	node *head1 = NULL, *head2 = NULL, **head_select = NULL;
	int choice, select_list;
	bool exit1 = false, exit2 = false;
	
	do
	{
		cout<<"\nSelect List\n1.List 1\n2.List 2\n3.Exit\nEnter choice: ";
		cin>>select_list;
		
		if (select_list == 1)
		{
			head_select = &head1;
		}
		else if (select_list == 2)
		{
			head_select = &head2;
		}
		else if (select_list == 3)
		{
			exit1 = true;
		}
		else
		{
			cout<<"Wrong input\n";
			continue;
		}

		do
		{
			exit2 = false;

			cout<<"\n0. Go back to list selection\n1. Insert member\n2. Insert President\n3. Insert secretary\n4. Insert member after position\n5. Display list"
			<<"\n6. Delete President\n7. Delete Secretary\n8. Delete Member\n9. Display total members\n10. Combine lists"
			<<"\n11. Exit\n\nEnter your choice: ";
			cin>>choice;

			switch (choice)
			{
				case 0:
					exit2 = true;
					break;
				
				case 1:
					append(head_select);
					break;
				
				case 2:
					push(head_select);
					break;
				
				case 3:
					append(head_select);
					break;

				case 4:
					insert_after(head_select);
					break;
				
				case 5:
					display_list(head_select);
					break;
				
				case 6:
					delete_node(head_select, true, false);
					break;

				case 7:
					delete_node(head_select, false, true);
					break;		

				case 8:
					delete_node(head_select, false, false);
					break;		
				
				case 9:
					display_count(head_select);
					break;
				
				case 10:
					concatenate(&head1, &head2);
					break;
				
				case 11:
					exit1 = true;
					exit2 = true;
					break;
				
				default:
					cout<<"Wrong input\n";
			}

		} while (!exit2);

	} while (!exit1);

//deallocating memory
delete_list(&head1);
delete_list(&head2);
}

/*
passing &obj instead of obj allows you to change its value (pass by reference)
e.g node **head_ref
to access the data member you need to dereference the pointer to pointer by including brackets as well
(*head_ref) -> prn ;
*/
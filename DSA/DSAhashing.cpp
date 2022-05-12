#include <bits/stdc++.h>

using namespace std;

#define SIZE 10

struct node
{
    string name;
    long long phone_no;
    node *next;
    node(string name, long long phone_no) // constructor
    {
        this->name = name;
        this->phone_no = phone_no;
        next = NULL;
    }
};

class hashtable
{
public:
    node *table[SIZE] = {};
    void insert_chaining(string name, long long phone_no);
    void insert_linear(string name, long long phone_no);
    void display_list(node *table_element);
    void display_chaining();
    void display_linear();
    bool isfull();
};

void hashtable::insert_chaining(string name, long long phone_no)
{
    int index = phone_no % SIZE;

    node *new_node = new node(name, phone_no);

    if (table[index] == NULL)
    {
        table[index] = new_node;
        return;
    }

    node *last = table[index];
    while (last->next != NULL)
    {
        last = last->next;
    }

    last->next = new_node;
}

void hashtable::display_list(node *table_element)
{
    node *temp = table_element;
    if (temp == NULL)
    {
        cout << "no element";
    }

    while (temp != NULL)
    {
        if (temp->next == NULL)
        {
            cout << temp->name << ": " << temp->phone_no;
            break;
        }
        cout << temp->name << ": " << temp->phone_no << " --> ";
        temp = temp->next;
    }
}

void hashtable::display_chaining()
{
    for (int i = 0; i < SIZE; i++)
    {
        cout << "index " << i << ": ";
        display_list(table[i]);
        cout << "\n";
    }
}

bool hashtable::isfull()
{
    bool flag = true;
    for (int i = 0; i < SIZE; i++)
    {
        if (table[i] == NULL)
        {
            flag = false;
            break;
        }
    }

    return flag;
}

void hashtable::insert_linear(string name, long long phone_no)
{
    if (isfull())
    {
        cout << "Value can't be inserted, table is full";
    }

    node *new_node = new node(name, phone_no);

    int index = phone_no % SIZE;
    while (table[index] != NULL)
    {
        index++;
        index = index % SIZE;
    }

    table[index] = new_node;
}

void hashtable::display_linear()
{
    for (int i = 0; i < SIZE; i++)
    {
        if (table[i] == NULL)
        {
            cout << "index " << i << ": "
                 << "No element"
                 << "\n";
            continue;
        }
        cout << "index " << i << ": " << table[i]->name << ": " << table[i]->phone_no << "\n";
    }
}

int main()
{
    cout << "Chaining\n";
    hashtable tab1;
    tab1.insert_chaining("kek1", 12);
    tab1.insert_chaining("kek2", 22);
    tab1.insert_chaining("kek3", 32);
    tab1.display_chaining();

    cout << "\nLinear Probing\n";
    hashtable tab2;
    tab2.insert_linear("kek1", 12);
    tab2.insert_linear("kek2", 22);
    tab2.insert_linear("kek3", 32);
    tab2.display_linear();

    // int choice = 0;
    // while (choice != 3)
    // {
    //     cout << "CHOOSE YOUR OPTION:\n";
    //     cout << "1. Linear Probing\n";
    //     cout << "2. Chaining\n";
    //     cout << "3. Exit\n";
    //     cout << "Enter your choice: ";
    //     cin >> choice;

    //     if (choice == 1)
    //     {
    //         int people;
    //         cout << "Enter number of people: ";
    //         cin >> people;

    //         hashtable tab1;
    //         for (int i = 0; i < people; i++)
    //         {
    //             string name;
    //             long long phone_no;
    //             cout << "Enter Name: ";
    //             cin >> name;
    //             cout << "Enter Phone: ";
    //             cin >> phone_no;
    //             tab1.insert_linear(name, phone_no);
    //         }
    //         cout << "Displaying table...\n";
    //         tab1.display_linear();
    //     }

    //     if (choice == 2)
    //     {
    //         int people;
    //         cout << "Enter number of people: ";
    //         cin >> people;

    //         hashtable tab2;
    //         for (int i = 0; i < people; i++)
    //         {
    //             string name;
    //             long long phone_no;
    //             cout << "Enter Name: ";
    //             cin >> name;
    //             cout << "Enter Phone: ";
    //             cin >> phone_no;
    //             tab2.insert_chaining(name, phone_no);
    //         }
    //         cout << "Displaying table...\n";
    //         tab2.display_chaining();
    //     }

    //     if (choice != 1 && choice != 2 && choice != 3)
    //     {
    //         cout << "ERROR: Wrong input\n";
    //     }
    // }
}
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class record
{
public:
    int item_code;
    string name;
    int cost;
    int quantity;
};

void accept(record &item)
{
    cout << "\n";
    cout << "Enter item code: ";
    cin >> item.item_code;
    cout << "Enter name: ";
    cin >> item.name;
    cout << "Enter cost: ";
    cin >> item.cost;
    cout << "Enter quantity: ";
    cin >> item.quantity;
    cout << "\n";
}

void display(vector<record> &v)
{
    cout << "\nDisplay records...\n";
    for (auto i : v)
    {
        cout << "item name: " << i.name << " ";
        cout << "item code: " << i.item_code << " ";
        cout << "item cost: " << i.cost << " ";
        cout << "item quantity: " << i.quantity;
        cout << "\n";
    }
}

bool comparator(const record &obj1, const record &obj2) //comparator (used by std::sort). Also passing by const ref is more memory efficient
{
    return (obj1.cost < obj2.cost);
}

void sort_records(vector<record> &v)
{
    sort(v.begin(), v.end(), comparator); //std::sort
}

void insert(vector<record> &v)
{
    record ele;
    accept(ele);
    v.push_back(ele);
}

bool operator==(const record &item1, const record &item2) //== operator is overloaded so that std::find can use it
{
    return (item1.cost == item2.cost);
}

void search(vector<record> &v)
{
    record temp;
    cout << "\nEnter the cost of item to be searched: ";
    cin >> temp.cost;

    vector<record>::iterator it;
    it = find(v.begin(), v.end(), temp);
    if (it != v.end())
    {
        cout << it->name << " has cost " << it->cost << "\n";
    }
    else
    {
        cout << "item of cost " << temp.cost << " is absent\n";
    }
}

void delete_record(vector<record> &v)
{
    record temp;
    cout << "\nEnter the cost of item to be removed: ";
    cin >> temp.cost;
    vector<record>::iterator it = v.begin();
    it = find(v.begin(), v.end(), temp);
    v.erase(it);
    while (it != v.end()) //while loop ensures that multiple occurences are also deleted
    {
        it = find(v.begin(), v.end(), temp);
        if (it != v.end()) //condition is required because v.erase(v.end()) is undefined behaviour
            v.erase(it);
    }
    cout << "items with cost " << temp.cost << " have been removed\n";
}

int main()
{
    vector<record> vec;
    int choice;
    while (true)
    {
        cout << "\n******CHOICE SELECT*******\n";
        cout << "Enter 1 to insert record\n";
        cout << "Enter 2 to display records\n";
        cout << "Enter 3 to search for a record\n";
        cout << "Enter 4 to sort all records\n";
        cout << "Enter 5 to delete record\n";
        cout << "Enter 6 to exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            insert(vec);
            break;
        case 2:
            display(vec);
            break;
        case 3:
            search(vec);
            break;
        case 4:
            sort_records(vec);
            break;
        case 5:
            delete_record(vec);
            break;
        case 6:
            exit(0);
        }
    }
}
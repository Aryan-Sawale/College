#include <bits/stdc++.h>
using namespace std;

#define MAX 10

struct Node
{
    int index;
    int cost;
    Node *next;

    Node(int index, int cost)
    {
        this->index = index;
        this->cost = cost;
        next = NULL;
    }
};

void insert(Node *&head, Node *x)
{
    Node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = x;
}

struct Graph
{
    Node *data[MAX];

    Graph()
    {
        for (int i = 0; i < MAX; i++)
        {
            data[i] = new Node(i, 0);
        }
    }

    void display(int cities)
    {
        for (int i = 0; i < cities; i++)
        {
            if (data[i]->next == NULL)
            {
                continue;
            }
            Node *temp = data[i]->next;

            cout << i << "->";

            while (temp->next != NULL)
            {
                cout << "[" << temp->index << "," << temp->cost << "]"
                     << "->";
                temp = temp->next;
            }
            cout << "[" << temp->index << "," << temp->cost << "]";
            cout << endl;
        }
    }

    void read()
    {
        int n;
        cout << "Enter the number of cities-\n";
        cin >> n;

        string cities[n];

        for (int i = 0; i < n; i++)
        {
            cout << "Enter the name of the city here-\n";
            cin >> cities[i];
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i != j)
                {
                    int choice;
                    cout << "Is there a flight path from city " + cities[i] + " to city " + cities[j] + " 1 for yes 0 for no-\n";
                    cin >> choice;

                    if (choice == 1)
                    {
                        int fuel;
                        cout << "Enter the fuel required from " + cities[i] + " to city " + cities[j] + "\n";
                        cin >> fuel;

                        Node *x = new Node(j, fuel);

                        insert(data[i], x);
                    }
                }
            }
        }
    }

    void dfs(vector<bool> &visited, int cities)
    {
        for (int i = 0; i < cities; i++)
        {
            Node *temp = data[i]->next;

            while (temp != NULL)
            {
                if (visited[temp->index] == 0)
                {
                    visited[temp->index] = 1;
                }
                temp = temp->next;
            }
        }
    }
};

int main()
{

    Graph g;
    g.read();

    int cities;
    cout << "Enter the number of cities here-\n";
    cin >> cities;

    g.display(cities);

    vector<bool> visited(cities, 0);

    g.dfs(visited, cities);

    bool flag = 1;
    for (int i = 0; i < cities; i++)
    {
        if (visited[i] == 0)
        {
            flag = 0;
            break;
        }
    }

    if (flag == 0)
    {
        cout << "The graph is not connected!\n";
    }
    else
    {
        cout << "The graph is connected!\n";
    }
    return 0;
}

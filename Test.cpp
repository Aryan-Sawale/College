#include <bits/stdc++.h>
using namespace std;

#define MAX 10
bool visited[MAX] = {};

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
	int vertices, edges;
	string cities[MAX];

	Graph()
	{
		for (int i = 0; i < MAX; i++)
		{
			data[i] = new Node(i, 0);
		}
	}

	void display(int cities_no)
	{
		for (int i = 0; i < cities_no; i++)
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

	// void read()
	// {
	//     int n;
	//     cout << "Enter the number of cities-\n";
	//     cin >> n;

	//     string cities[n];

	//     for (int i = 0; i < n; i++)
	//     {
	//         cout << "Enter the name of the city here-\n";
	//         cin >> cities[i];
	//     }

	//     for (int i = 0; i < n; i++)
	//     {
	//         for (int j = 0; j < n; j++)
	//         {
	//             if (i != j)
	//             {
	//                 int choice;
	//                 cout << "Is there a flight path from city " + cities[i] + " to city " + cities[j] + " 1 for yes 0 for no-\n";
	//                 cin >> choice;

	//                 if (choice == 1)
	//                 {
	//                     int fuel;
	//                     cout << "Enter the fuel required from " + cities[i] + " to city " + cities[j] + "\n";
	//                     cin >> fuel;

	//                     Node *x = new Node(j, fuel);

	//                     insert(data[i], x);
	//                 }
	//             }
	//         }
	//     }
	// }

	void read()
	{
		cout << "Enter no. of cities and flights: ";
		cin >> vertices >> edges;

		int u, v, weight;
		for (int i = 0; i < edges; i++)
		{
			cout << "\nEnter the starting city, destination city and fuel: ";
			cin >> u >> v >> weight;

			Node *x = new Node(v, weight);
			Node *y = new Node(u, weight);
			insert(data[u], x);
			insert(data[v], y);
		}

		cout << "\ndisplaying adjacency list:\n";
		for (int i = 0; i < vertices; i++)
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

	// void dfs(vector<bool> &visited, int cities)
	void DFS()
	{
		for (int i = 0; i < vertices; i++)
		{
			Node *temp = data[i]->next;

			while (temp != NULL)
			{
				if (!visited[temp->index])
				{
					visited[temp->index] = true;
				}
				temp = temp->next;
			}
		}
	}

	void check_connected()
	{
		DFS();
		bool flag = true;
		for (int i = 0; i < vertices; i++)
		{
			if (!visited[i])
			{
				flag = false;
				break;
			}
		}

		if (flag)
		{
			cout << "\n\nGraph is connected\n";
		}
		else
		{
			cout << "\n\nGraph is not connected\n";
		}
	}
};

int main()
{

	Graph g;
	g.read();
	g.check_connected();

	return 0;
}

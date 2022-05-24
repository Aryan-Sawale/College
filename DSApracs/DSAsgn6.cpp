#include <iostream>

using namespace std;

#define MAX 10
bool visited[MAX] = {};

class Graph
{
public:
    int adj_mat[MAX][MAX] = {}; // intialize all values to 0
    string cities[MAX];
    int vertices = MAX, edges;
    void create_graph();
    void display();
    void DFS();
    void check_connected();
};

void Graph::create_graph()
{
    cout << "Enter no. of cities and flights: ";
    cin >> vertices >> edges;

    for (int i = 0; i < vertices; i++)
    {
        cout << "Enter city " << i << ": ";
        cin >> cities[i];
    }

    int u, v, weight;
    for (int i = 0; i < edges; i++)
    {
        cout << "\nEnter the starting city, destination city and fuel: ";
        cin >> u >> v >> weight;
        adj_mat[u][v] = adj_mat[v][u] = weight;
    }
}

void Graph::display()
{
    cout << "Graph:\n";
    for (int i = 0; i < vertices; i++)
    {
        for (int j = 0; j < vertices; j++)
        {
            cout << adj_mat[i][j] << " ";
        }
        cout << "\n";
    }
}

void Graph::DFS()
{
    // visited[vertex] = true;
    // for (int j = 0; j < vertices; j++)
    // {
    //     if (adj_mat[vertex][j] != 0)
    //     {
    //         if (!visited[j])
    //         {
    //             DFS(j);
    //         }
    //     }
    // }
    for (int i = 0; i < vertices; i++)
    {
        for (int j = 0; j < vertices; j++)
        {
            if (adj_mat[i][j] != 0)
            {
                visited[j] = true;
            }
        }
    }
}

void Graph::check_connected()
{

    for (int i = 0; i < vertices; i++)
    {
        for (int j = 0; j < vertices; j++)
        {
            if (adj_mat[i][j] != 0)
            {
                cout << "\nPath: " << cities[i] << " --> " << cities[j] << " fuel: " << adj_mat[i][j];
            }
        }
    }

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

int main()
{
    Graph test_graph;
    test_graph.create_graph();
    test_graph.display();
    test_graph.check_connected();
}
#include <iostream>

using namespace std;

#define MAX 10
#define INF 9999
bool visited[MAX] = {};

class Graph
{
public:
    int adj_mat[MAX][MAX] = {}; // intialize all values to 0
    string cities[MAX];
    int vertices = MAX, edges;
    void create_graph();
    void display();
    void DFS(int vertex);
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

// void check_connected(Graph graph)
// {
//     int verts = graph.vertices;
//     int counter = 0;
//     for (int i = 0; i < verts; i++)
//     {
//         bool flag = false;
//         for (int j = 0; j < verts; j++)
//         {
//             if (graph.adj_mat[i][j] != 0)
//             {
//                 flag = true;
//                 cout << "\nPath: " << graph.cities[i] << " --> " << graph.cities[j] << " fuel: " << graph.adj_mat[i][j];
//             }
//         }

//         if (flag)
//         {
//             counter++;
//         }
//     }

//     if (counter == verts)
//     {
//         cout << "\n\nGraph is connected\n";
//     }
//     else
//     {
//         cout << "\n\nGraph is not connected\n";
//     }
// }

void Graph::DFS(int vertex)
{
    visited[vertex] = true;
    for (int i = 0; i < vertices; i++)
    {
        for (int j = 0; j < vertices; i++)
        {
            if (adj_mat[i][j] != 0)
            {
                if (!visited[j])
                {
                    DFS(j);
                }
            }
        }
    }
}

void Graph::check_connected()
{
    DFS(0);
    cout << "point 1\n";
    bool flag = true;
    for (int i = 0; i < vertices; i++)
    {
        if (!visited[i])
        {
            flag = false;
            break;
        }
    }
    cout << "point 2\n";
    if (flag)
    {
        cout << "\n\nGraph is connected\n";
    }
    else
    {
        cout << "\n\nGraph is not connected\n";
    }
    cout << "point 3\n";
}

int main()
{
    Graph test_graph;
    test_graph.create_graph();
    test_graph.display();
    test_graph.check_connected();
}
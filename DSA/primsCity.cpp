#include <iostream>

using namespace std;

#define MAX 10
#define INF 9999;

class Graph
{
public:
    int adj_mat[MAX][MAX] = {}; // intialize all values to 0
    int vertices = MAX, edges;
    void create_graph();
    void display();
};

void Graph::create_graph()
{
    cout << "Enter vertices and edges: ";
    cin >> vertices >> edges;
    int u, v, weight;
    for (int i = 0; i < edges; i++)
    {
        cout << "\nEnter the source vertex, destination vertex and weight: ";
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

void displayPrim(int selected_vertex[], int res, Graph graph)
{
    cout << "\nMST:";
    int verts = graph.vertices;
    for (int i = 1; i < verts; i++)
    {
        cout << "\nEdge added: " << selected_vertex[i] << " --> " << i << " weight: " << graph.adj_mat[selected_vertex[i]][i];
    }

    cout << "\n\nMinimum cost: " << res;
}

void prim(Graph graph)
{
    int selected_vertex[MAX];
    int verts = graph.vertices;
    int key[verts], res = 0;
    for (int i = 0; i < verts; i++)
    {
        key[i] = INF;
    }
    key[0] = 0;
    bool mSet[verts] = {false};

    for (int count = 0; count < verts; count++)
    {
        int u = -1;
        for (int i = 0; i < verts; i++) // find min value from key and set it as u
        {
            if (!mSet[i] && (u == -1 || key[i] < key[u]))
            {
                u = i;
            }
        }

        mSet[u] = true;
        res = res + key[u];

        for (int i = 0; i < verts; i++) // find min edge from unvisited vertices and update their key values
        {
            if ((graph.adj_mat[u][i] != 0) && !mSet[i] && (graph.adj_mat[u][i] < key[i]))
            {
                key[i] = graph.adj_mat[u][i];
                selected_vertex[i] = u;
            }
        }
    }
    displayPrim(selected_vertex, res, graph);
}

int main()
{
    Graph test_graph;
    test_graph.create_graph();
    prim(test_graph);
}
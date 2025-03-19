#include <iostream>
#include <climits>

#define INF INT_MAX
#define V 5

using namespace std;

int minDistance(int dist[], bool visited[])
{
    int min = INF, min_index;
    for (int v = 0; v < V; v++)
        if (!visited[v] && dist[v] <= min)
        {
            min = dist[v];
            min_index = v;
        }
    return min_index;
}

void printPath(int parent[], int j)
{
    if (parent[j] == -1)
    {
        cout << j << " ";
        return;
    }
    printPath(parent, parent[j]);
    cout << "-> " << j << " ";
}

void dijkstra(int graph[V][V], int src)
{
    int dist[V];
    bool visited[V];
    int parent[V];

    for (int i = 0; i < V; i++)
    {
        dist[i] = INF;
        visited[i] = false;
        parent[i] = -1;
    }

    dist[src] = 0;

    for (int count = 0; count < V - 1; count++)
    {
        int u = minDistance(dist, visited);
        visited[u] = true;

        for (int v = 0; v < V; v++)
        {
            if (!visited[v] && graph[u][v] && dist[u] != INF && dist[u] + graph[u][v] < dist[v])
            {
                dist[v] = dist[u] + graph[u][v];
                parent[v] = u;
            }
        }
    }

    cout << "Vertex \t Distance from Source\t Path\n";
    for (int i = 0; i < V; i++)
    {
        cout << i << " \t\t " << dist[i] << "\t\t ";
        printPath(parent, i);
        cout << endl;
    }
}

int main()
{
    int graph[V][V] = {
        {0, 10, 20, 0, 0},
        {10, 0, 5, 16, 0},
        {20, 5, 0, 20, 1},
        {0, 16, 20, 0, 2},
        {0, 0, 1, 2, 0}};

    int source = 0;
    dijkstra(graph, source);

    return 0;
}

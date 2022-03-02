// Create a Graph, print it
// Representation of Grah in cpp
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Method 1 Adjacency Matrix
    /* Adjacency Matrix is a 2D array of size V x V where V is the number of vertices in a graph. Let the 2D array be adj[][], a slot adj[i][j] = 1 indicates that there is an edge from vertex i to vertex j. Adjacency matrix for undirected graph is always symmetric. Adjacency Matrix is also used to represent weighted graphs. If adj[i][j] = w, then there is an edge from vertex i to vertex j with weight w.
     */
    void adjacencyMatrix(int n, int m)
    {
        int adjMat[n + 1][n + 1];
        for (int i = 0; i < m; i++)
        {
            int u, v;
            cin >> u >> v;
            adjMat[u][v] = 1;
            adjMat[v][u] = 1;
        }
        return;
    } // Space Complexity O{(n+1)(n+1)}

    // Method 1 Adjacency List
    /* An array of lists is used. The size of the array is equal to the number of vertices. Let the array be an array[]. An entry array[i] represents the list of vertices adjacent to the ith vertex. This representation can also be used to represent a weighted graph. The weights of edges can be represented as lists of pairs. Following is the adjacency list representation of the above graph.
     */
    void adjacencyList(int n, int m)
    {
        vector<int> adjList[n + 1];
        // If weight of edges is mentioned we use vector pair and while pushing we push weight and node in apair
        // vector<pair<int, int>> adjList(n+1);
        for (int i = 0; i < m; i++)
        {
            int u, v;
            cin >> u >> v;
            adjList[u].push_back(v);
            adjList[v].push_back(u); // We Don't need this line is graph is Directed
        }
        return;
    } // Space Complexity O(N+2E) where N & E are nodes and edges respectively

    // A utility function to print the adjacency list
    // representation of graph
    void printGraph(vector<int> adj[], int V)
    {
        for (int v = 0; v < V; ++v)
        {
            cout << "\n Adjacency list of vertex " << v << "\n head ";
            for (auto x : adj[v])
                cout << "-> " << x;
            cout << "\n";
        }
    }
};

int32_t main()
{
    /* Constructed Graph from given input as
         1-----2
        | \     \
        |  \     \
        |   \     4
        |    \  /
        5-----3
    */
    int n = 5, m = 7;

    Solution graph;
    vector<int> adjList[n + 1];
    // If weight of edges is mentioned we use vector pair and while pushing we push weight and node in apair
    // vector<pair<int, int>> adjList(n+1);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adjList[u].push_back(v);
        adjList[v].push_back(u); // We Don't need this line is graph is Directed
    }

    graph.printGraph(adjList, m);
    cout << endl;

    return 0;
}
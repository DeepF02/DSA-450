// Implement BFS (Breath First Search) algorithm
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Function to detect cycle in an undirected graph using BFS.
    bool cycleBFS(int i, int V, vector<int> adj[], vector<bool> &vis)
    {
        queue<pair<int, int>> q;// we push curr and previous vertex in queue
        q.push({i, -1});
        vis[i] = 1;
        while (!q.empty())
        {
            int node = q.front().first;
            int prev = q.front().second;
            q.pop();
            for (auto x : adj[node])
            {
                if (!vis[x])
                {
                    q.push({x, node});// we push curr vertex i.e x and prev vertex i.e node
                    vis[x] = 1;
                }
                else if (prev != x)// if curr vertex isn't equal to prev i.e it has been visted before and there is a loop
                    return 1;
            }
        }
        return 0;
    }

    // Function to detect cycle in an undirected graph using DFS.
    bool cycleDFS(int node, int parent, vector<int> adj[], vector<bool> &vis)
    {
        vis[node]=1;// Mark the current node as visited

        // Recur for all the vertices adjacent to this vertex
        for (auto x : adj[node]){
            if (!vis[x]){ // If an adjacent vertex is not visited, then recur for that adjacent
                if(cycleDFS(x, node, adj, vis))return 1; // if in any recursion we get loop then it will be true for all recursion
            }
            else if (parent != x)// If an adj vertex is visited and isn't parent of current vertex, then there exists a cycle in the graph.
                return 1;
        }
        return 0;
    }

    // Function to detect cycle in an undirected graph.
    bool isCyclic(int V, vector<int> adj[])
    {
        // Code here
        vector<bool> vis(V + 1, 0);
        // We do BFS to detect any cycle
        for (int i = 0; i < V; i++)
            if (!vis[i]){
                // if (cycleBFS(i, V, adj, vis)) return 1;
                if (cycleDFS(i, V, adj, vis)) return 1;
            }

        return 0;
    } // Time Complexity: O(N+E) && Auxillary Space: O(N+E +N +N)=O(3N+E)
};

int32_t main()
{
    /* Constructed Graph from given input as
        1----0----3
        |   /     |
       |  /      |
       2        4

    */

    Solution Graph;

    // A graph with cycle
    vector<int> adjList[5];
    adjList[1].push_back(0);
    adjList[0].push_back(2);
    adjList[2].push_back(1);
    adjList[0].push_back(3);
    adjList[3].push_back(4);

    Graph.isCyclic(5, adjList)? cout << "Graph contains cycle\n":cout << "Graph doesn't contain cycle\n";

    // A graph without cycle
    // vector<int> adjList[3];
    // adjList[0].push_back(1);
    // adjList[1].push_back(2);
 
    // Graph.isCyclic(3, adjList)?cout << "Graph contains cycle\n": cout << "Graph doesn't contain cycle\n";

    return 0;
}
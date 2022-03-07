// Detect Cycle in Directed Graph using BFS/DFS Algo 
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Function to detect cycle in an undirected graph using BFS.
    // bool cycleBFS(int i, int V, vector<int> adj[], vector<bool> &vis)
    // {
    //     queue<pair<int, int>> q;// we push curr and previous vertex in queue
    //     q.push({i, -1});
    //     vis[i] = 1;
    //     while (!q.empty())
    //     {
    //         int node = q.front().first;
    //         int prev = q.front().second;
    //         q.pop();
    //         for (auto x : adj[node])
    //         {
    //             if (!vis[x])
    //             {
    //                 q.push({x, node});// we push curr vertex i.e x and prev vertex i.e node
    //                 vis[x] = 1;
    //             }
    //             else if (prev != x)// if curr vertex isn't equal to prev i.e it has been visted before and there is a loop
    //                 return 1;
    //         }
    //     }
    //     return 0;
    // }

    // Function to detect cycle in an directed graph using DFS.
    bool cycleDFS(int node, vector<int> adj[], vector<bool> &vis, vector<bool> &dfsVis)
    {
        vis[node]=1;// Mark the current node as visited
        dfsVis[node]=1;// Mark the dfs visted array element as visted

        // Recur for all the vertices adjacent to this vertex
        for (auto x : adj[node]){
            if (!vis[x]){ // If an adjacent vertex is not visited, then recur for that adjacent
                if(cycleDFS(x, adj, vis, dfsVis))return 1; // if in any recursion we get loop then it will be true for all recursion
            }
            else if (dfsVis[x])// If dfs visited array was already visted, then there exists a cycle in the graph.
                return 1;
        }
        dfsVis[node]=0; //When we come out of recursion cycle we mark dfsVis array node as unvisited 
        return 0;
    }

    // Function to detect cycle in an undirected graph.
    bool isCyclic(int V, vector<int> adj[])
    {
        // Code here
        vector<bool> vis(V, 0);
        vector<bool> dfsVis(V, 0);
        // We do DFS to detect any cycle
        for (int i = 0; i < V; i++)
            if (!vis[i]){
                // if (cycleBFS(i, V, adj, vis)) return 1;
                if (cycleDFS(i, adj, vis, dfsVis)) return 1;
            }

        return 0;
    } // Time Complexity: O(N+E) && Auxillary Space: O(2N)
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
    // vector<int> adjList[5];
    // adjList[1].push_back(0);
    // adjList[0].push_back(2);
    // adjList[2].push_back(1);
    // adjList[0].push_back(3);
    // adjList[3].push_back(4);

    // Graph.isCyclic(5, adjList)? cout << "Graph contains cycle\n":cout << "Graph doesn't contain cycle\n";

    // A graph without cycle
    vector<int> adjList[3];
    adjList[0].push_back(1);
    adjList[1].push_back(2);
 
    Graph.isCyclic(3, adjList)?cout << "Graph contains cycle\n": cout << "Graph doesn't contain cycle\n";

    return 0;
}
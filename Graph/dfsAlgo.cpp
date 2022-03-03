// Implement DFS (Dept First Search) algorithm
#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    void dfs(int node, vector<int> adj[], vector<bool> &vis, vector<int> &ans)
    {
        ans.push_back(node); // we push node in our ans
        vis[node] = 1; // Whenever we push a node in queue we mark it set/true in visited array
        for (auto x : adj[node]) // // Recur for all the vertices adjacen to this vertex
            if (!vis[x])// If the node is not visited we do recursiveDFS search for that node
                dfs(x, adj, vis, ans); //this way we go to all dept nodes first before returning to adjacent nodes
        return;
    }

public:
    // Function to return a list containing the DFS traversal of the graph.
    vector<int> dfsOfGraph(int V, vector<int> adj[])
    {
        // Code here
        vector<bool> vis(V + 1, 0);
        vector<int> ans;
        for (int i = 0; i < V; ++i)// If the given graph is in components we use this for loop to move to next unconnected component
            if (!vis[i])// If the node is not visited we do DFS search for that node
                dfs(i, adj, vis, ans);

        return ans;
    }// Time Complexity: O(N+E) && Auxillary Space: O(N+E +N +N)=O(3N+E)
};

int32_t main()
{
    /* Constructed Graph from given input as
         0
       / | \
      /  |  \
     1   2   3
        /
       4

    */

    Solution Graph;

    vector<int> adjList[5];
    adjList[0].push_back(1);
    adjList[0].push_back(2);
    adjList[0].push_back(3);
    adjList[2].push_back(4);

    cout << "Following is depth First Traversal ";
    vector<int> ans = Graph.dfsOfGraph(4, adjList);
    for (auto x : ans)
        cout << x << " ";
    cout << endl;

    return 0;
}
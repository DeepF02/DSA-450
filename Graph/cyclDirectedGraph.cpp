// Detect Cycle in Directed Graph using BFS/DFS Algo 
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Function to detect cycle in an directed graph using Kahn's Algo (BFS Algo).
    bool cycleBFS(int V, vector<int> adj[], vector<int>&indegree){
        queue<int>q; // We maintain a queue 
	    // And push each node that has 0 indegree edges
        for(int i=0; i<V; ++i)if(!indegree[i])q.push(i);
        int cnt=0; //This is the counter variable to count no. of nodes while we do BFS traversal
        while(!q.empty()){  //We run BfS till the queue is empty
            int currNode=q.front();
            q.pop(); //We pop the currNode out of queue
            ++cnt;//We do cnt++ each time we visit a new node;
            for(auto it: adj[currNode]){
                --indegree[it];//Once we visted that node we reduce it's indegree by 1
	            if(!indegree[it])q.push(it); //If a nodes indegree becomes 0 we push that into our queue
            }
        }
        // As Topological Sorting is Only Possible for Directed Acycllic Graph
        // So if cnt equal to no.of vertices of graph that means there is no cycle and topo sort was successful
        // But if not then topo sort failed and cycle exist in the given graph
        return (cnt==V)?0:1;
    }

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
        // Method 1: By using DFS ALgo
        // vector<bool> vis(V, 0);
        // vector<bool> dfsVis(V, 0);
        // // We do DFS to detect any cycle
        // for (int i = 0; i < V; i++)
        //     if (!vis[i]){
        //         // if (cycleBFS(i, V, adj, vis)) return 1;
        //         if (cycleDFS(i, adj, vis, dfsVis)) return 1;
        //     }

        // return 0;

        // Method 2: By using Kahn's Algo (BFS ALgo)
        vector<int>indegree(V, 0);// indegree of a node is no. of edges connecting towards that particular node
        for(int i=0; i<V; ++i){//We traverse through each node
            for(auto it: adj[i])++indegree[it]; //If that node has adjacent nodes we do increment to that adjacent node's in array
        }
        return cycleBFS(V, adj, indegree);
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
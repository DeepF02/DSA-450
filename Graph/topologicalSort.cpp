// Implement Topological Sort
#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    // Function to get Topological sort of given directed graph using DFS
    void topologicalSortDFS(int node, vector<int> adj[], vector<bool> &vis, stack<int> &s)
    {
        vis[node] = 1;            // If a node is unvisited we mark it visted in array
        for (auto it : adj[node]) // Recur for all the vertices adjacen to this vertex
        {
            if (!vis[it]) // If the node is not visited we do recursiveDFS search for that node
                topologicalSortDFS(it, adj, vis, s);
        }
        s.push(node); // After coming out of recursion call we push that node into our stack
    } // Time Complexity: O(N+E) &&  Space: O(N+E +N +N)=O(3N+E)

    // Function to get Topological sort of given directed graph using Kahn's Algo
    vector<int> topologicalSortBFS(int V, vector<int> adj[], vector<int>&indegree){
	    vector<int>ans;
	    queue<int>q; // We maintain a queue 
	    // And push each node that has 0 indegree edges
	    for(int i=0; i<V; ++i)if(!indegree[i])q.push(i);
	    while(!q.empty()){ //We run BfS till the queue is empty
	        int node=q.front();
	        for(auto it: adj[node]){
	            indegree[it]--; //Once we visted that node we reduce it's indegree by 1
	            if(!indegree[it])q.push(it); //If a nodes indegree becomes 0 we push that into our queue
	        }
	        ans.push_back(node); //Once we visted all adjacent nodes of our queue's front element we push it to our ans
	        q.pop(); // And pop that node out of queue
	    }
	    return ans;
	}// Time Complexity: O(N+E) &&  Space: O(N+N)=O(2N)

public:
    // Function to return list containing vertices in Topological order.
    vector<int> topoSort(int V, vector<int> adj[])
    {
        // Code here
        // Method 1: Using DFS algo
        // vector<bool> vis(V, 0);
        // stack<int> s; // We maintain a stack and push each node into it after each recursion call is over
        // for (int i = 0; i < V; ++i) // If the given graph is in components we use this for loop to move to next unconnected component
        // {               
        //     if (!vis[i]) // If the node is not visited we do DFS search for that node
        //         topologicalSortDFS(i, adj, vis, s);
        // }

        // vector<int> ans;
        // // We push all nodes in stack into our array till its empty
        // while (!s.empty())
        // {
        //     ans.push_back(s.top());
        //     s.pop();
        // }
        // return ans;

        // Method 2: Using Kahn's Algorithm i.e also a BFS Algo
        //Instead of visted array we make a indegree Array
        vector<int>indegree(V, 0);// indegree of a node is no. of edges connecting towards that particular node
	    for(int i=0; i<V; ++i){//We traverse through each node
	        for(auto it:adj[i])indegree[it]++;  //If that node has adjacent nodes we do increment to that adjacent node's in array
	    }
	    return topologicalSortBFS(V, adj, indegree);
    }
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
     
    // Graph 1
    vector<int> adjList[5];
    adjList[0].push_back(1);
    adjList[0].push_back(2);
    adjList[0].push_back(3);
    adjList[2].push_back(4);

    // Graph 2
    // vector<int> adjList[6];
    // adjList[5].push_back(2);
    // adjList[5].push_back(0);
    // adjList[4].push_back(0);
    // adjList[4].push_back(1);
    // adjList[2].push_back(3);
    // adjList[3].push_back(1);

    cout << "Following is a Topological Sort of the given Directed Acycalic Graph : ";
    vector<int> ans = Graph.topoSort(5, adjList);
    for (auto x : ans)
        cout << x << " ";
    cout << endl;

    return 0;
}
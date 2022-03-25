// Find sum of weights of edges of the Minimum Spanning Tree.
// Implement Prim’s Algorithm
#include <bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    // Spanning tree is a graph converted into tree with n nodes and N-1 edges (N=nodes in graph)
    //Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<pair<int, int>> adj[])
    {
        // code here
        // Parent array is usefull when we need to print each node of tree hence it will store parent of each element
        vector<int>weightKey(V, 10001), parent(V, -1); // weightKey array will store weight of each egde corresponding to its node
        vector<bool>mst(V, 0); //Minimum spanning tree each nodes will be marked false initiallly
        weightKey[0]=0; //We start from 0 hence weightKey[0] will have weight 0
        //We define minheap to store minimum edge weight node in weightKey array
        priority_queue<pair<int,int>>pq;
        pq.push({0, 0}); // we push initial weight and node in minheap
        
        // Brute force for prim algo which take 
        // Time Complexity: O((N*3N))> O(N^2) &&  Space: O(N+N+N)=O(3N)
        // for(int i=0; i<V; ++i){
        //     int mini=INT_MAX, u;
        //     for(auto it=0; it<V; ++it)
        //         if(!mst[it] && weightKey[it]<mini)
        //             mini=weightKey[it], u=it;
        //     mst[u]=1;
        //     for(auto it: adj[u]){
        //         int node=it[0];
        //         int weight=it[1];
        //         if(!mst[node] && weight<weightKey[node])parent[node]=u, weightKey[node]=weight;
        //     }
        // }

        // Efficient method for prim algo using priorityQueue (minHeap)
        while(!pq.empty()){// We iterate till heap is empty
            int u=pq.top().second; // u represents miminum weighted edge node i.e. at top of minHeap
            pq.pop();
            mst[u]=true; //Once we take out a node out of heap we mark its value true in mst
            for(auto it: adj[u]){
                int node=it.first;
                int weight=it.second;
                // graph[u][node] is non zero only for adjacent vertices of m 
                // mstSet[node] is false for vertices not yet included in MST 
                // Update the weightKey only if graph[u][node] is smaller than weightKey[node] 
                if(!mst[node] && weight<weightKey[node]){
                    parent[node]=u;
                    weightKey[node]=weight;
                    pq.push({-weight, node});
                }
            }
        }
        int ans=0;
        for(auto i=1; i<V; ++i)ans+=weightKey[i];
        return ans;
    }// Time Complexity: O(3N*log(N)*E)> O(N.log(N)) &&  Space: O(N+N+N)=O(3N)
};

int32_t main()
{
    /* Constructed Graph from given input as
         0
      1/ |\2
      / 2| \
     1   2   3
        /2
       4

    */

    Solution Graph;
     
    // Graph 1
    vector<pair<int, int>> adjList[5];
    adjList[0].push_back({1, 1});
    adjList[0].push_back({2, 2});
    adjList[0].push_back({3, 2});
    adjList[1].push_back({0, 1});
    adjList[3].push_back({0, 2});
    adjList[2].push_back({0, 2});
    adjList[2].push_back({4, 2});
    adjList[4].push_back({2, 2});


    cout << "Following is a Minimum Spanning tree edges Sum: "<<Graph.spanningTree(5, adjList)<< endl;

    return 0;
}
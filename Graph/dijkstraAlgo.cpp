// Given a graph and a source vertex in the graph, find the shortest paths from the source to all vertices in the given graph.
// Dijkstra Algo
#include <bits/stdc++.h>
using namespace std;

class Solution
{
    public:
	//Function to find the shortest distance of all the vertices from the source vertex S.
    vector <int> dijkstra(int V, vector<pair<int, int>> adj[], int S)
    {
        // Code here
        //Here we use distance array instead of visited array as used in Bfs it will store minimum distance require to visit that node 
        vector<int>distn(V, INT_MAX);
        priority_queue<pair<int, int>>minHeap; // we'll convert maxHeap into minHeap by taking neagtive of storing elements
        // priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>> >pq; //official way of making pq of minHeap
        
        // As source node will take 0 distance to vist we mark it as 0
        distn[S]=0;
        // Push source node and its distance in minHeap
        minHeap.push({0, S}); //distn, node
        while(!minHeap.empty()){
            int prevNode=minHeap.top().second; // curr node
            minHeap.pop();
            for(auto it:adj[prevNode]){
                int nextNode=it.first; // next node to vist after this node as per adjacency list of given graph
                int nextDist=it.second; // Distn of node
                // If distance of this node saved in distn array is more then the distn took to visit it "this time"
                // This time is nothing but previous distance + distance given of this node
                // then we update the distnace in distn array and push it in minHeap
                if(distn[nextNode]>distn[prevNode] + nextDist){
                    distn[nextNode]=distn[prevNode] + nextDist;
                    minHeap.push({-distn[nextNode], nextNode});
                }
            }
        }
        return distn;
    }// Time Complexity: O((N+E)Log(N)) ~ O(Nlog(N)) &&  Space: O(N+N)=O(2N)
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


    cout << "Following is a distance from Source of all vertices: ";
    vector<int> ans = Graph.dijkstra(5, adjList, 0);
    for (auto x : ans)
        cout << x << " ";
    cout << endl;

    return 0;
}
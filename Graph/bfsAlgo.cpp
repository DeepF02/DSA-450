// Implement BFS (Breath First Search) algorithm 
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int V, vector<int> adjList[]) {
        // Code here
        vector<int>BFS; //We will return our ans in this bfs vector in this  
        vector<bool>vist(V, 0); // We create a visting array for all vertices and mark them 0 initially
        for(int i=0; i<V; ++i){ // If the given graph is in components we use this for loop to move to next unconnected component
            if(!vist[i]){ // If the node is not visited we do BFS search for that node
                queue<int>q; // we create a queue to store the nodes
                q.push(i); // we push our first node in queue
                vist[i]=1; //Whenever we push a node in queue we mark it set/true in visited array
                while(!q.empty()){ // We push all adjacent nodes in queue until its empty
                    int node = q.front(); // this store the node value
                    q.pop(); // as soon as we store node we pop it out of queue 
                    BFS.push_back(node); // we push it in our ans
                    for(auto it: adjList[node]){ // Then we check all adjacent nodes of this node through our adjaceny List
                        if(!vist[it]){
                            q.push(it);
                            vist[it]=1;
                        }
                    }
                }
            }
        }
        return BFS;
    }// Time Complexity: O(N+E) && Auxillary Space: O(N+E +N)=O(2N+E)
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

    cout << "Following is Breadth First Traversal ";
    vector<int>ans = Graph.bfsOfGraph(4, adjList);
    for(auto x: ans)cout<<x<<" ";
    cout << endl;

    return 0;
}
// Check whether a graph is Bipartite or Not
#include <bits/stdc++.h>
using namespace std;

class Solution
{

    // A Bipartite Graph is a graph whose vertices can be divided into two independent sets, U and V such that every edge (u, v) either connects a vertex from U to V or a vertex from V to U. In other words, for every edge (u, v), either u belongs to U and v to V, or u belongs to V and v to U. We can also say that there is no edge that connects vertices of same set. This is gfg defination Bipartite graphs

    // In simle words Bipartite graph is a graph that can be colored using two colors such that no 2 adjacent nodes have same color/identity
    // So Except Odd no. of cycle nodes containing graphs all other graph can be a bipartite graph 


public:
    
    // Function to detect odd/even no. of cycle in an undirected graph using BFS.
	bool bipartiteBFS(int i, vector<int>adj[], int colorArr[]){
	    queue<int>q;
	    q.push(i);
	   // colorArr[i]=0;// we can assign first node any color
	    colorArr[i]=1; // we assign (no. 1)/(color any) to first node of array
	    while(!q.empty()){// we do bdf search
	        int node=q.front();
	        q.pop();
	        for(auto x:adj[node]){
	            if(colorArr[x]==-1){// if color if not assigned we assign a color
	                q.push(x);
                // We assign opposite color/no. of adjacent node to curr node
	               // (colorArr[node]==0)?colorArr[x]=1:colorArr[x]=0;
	                colorArr[x]=1-colorArr[node]; // same as line 21
	            }
                // If 2 adjacent nodes have same color/no. i.e. its not a Bipartite graph
	            else if(colorArr[x]==colorArr[node]) return 0; 
	        }
	    }
	    return 1;
	}// Time Complexity: O(N+E) && Auxillary Space: O(N+E)

    // Function to detect odd/even no. of cycle in an undirected graph using DFS.
    bool bipartiteDFS(int node, vector<int>adj[], int colorArr[]){
	    if(colorArr[node]==-1)colorArr[node]=1;// we assign (no. 1)/(color any) to the node if it was not visided in array
	    for(auto x:adj[node]){
	        if(colorArr[x]==-1){// if color if not assigned we assign a color
	            colorArr[x]=1-colorArr[node]; // We assign opposite color/no. of adjacent node to curr node
	            if(!bipartiteDFS(x, adj, colorArr)) return 0;// if in any recursion we get false then it will be flase for all recursion
	        }else if(colorArr[x]==colorArr[node]) return 0;// If 2 adjacent nodes have same color/no. i.e. its not a Bipartite graph
	    }
	    return 1;
	}// Time Complexity: O(N+E) && Auxillary Space: O(N+E) + O(N) + O(N)



    // Function to detect cycle in an undirected graph.
    bool isBipartite(int V, vector<int> adj[])
    {
        // Code here
        // vector<bool> colorArr(V , -1);
        int colorArr[V];
	    memset(colorArr, -1, sizeof colorArr);//memset assigns -1 to each element of array same as the line 38
        // We do BFS/DFS to detect whether the graph has any odd numbered cycle
        for (int i = 0; i < V; i++){
            if (colorArr[i]==-1){
                // if (!bipartiteBFS(i, adj, colorArr)) return 0;
                if (!bipartiteDFS(i, adj, colorArr)) return 0;
            }
        }
        return 1;
    } 
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

    // A graph with odd no. cycle node
    vector<int> adjList[5];
    adjList[1].push_back(0);
    adjList[0].push_back(2);
    adjList[2].push_back(1);
    adjList[0].push_back(3);
    adjList[3].push_back(4);

    Graph.isBipartite(5, adjList)? cout << "Graph is Bipartite\n":cout << "Graph is not Bipartite\n";

    // A graph with even no. cycle node
    // vector<int> adjList[3];
    // adjList[0].push_back(1);
    // adjList[1].push_back(2);
 
    // Graph.isBipartite(3, adjList)?cout << "Graph is Bipartite\n": cout << "Graph isn't Bipartite\n";

    return 0;
}
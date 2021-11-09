// Merge “K” sorted arrays. [ IMP ]
#include <bits/stdc++.h>
using namespace std;

class Solution{
public:	
    public:
    //Function to merge k sorted arrays.
    vector<int> mergeKArrays(vector<vector<int>> arr, int K)
    {
        vector<int> ans;
        priority_queue<int, vector<int>, greater<int>> minHeap;
        for(int i=0; i<K; i++){
            for(int j=0; j<K; j++) minHeap.push(arr[i][j]);
        }
        while(!minHeap.empty()){
            int i=minHeap.top();
            ans.push_back(i);
            minHeap.pop(); 
        }
        return ans;
    }// Time Complexity: O(N*KLogK) Auxiliary Space: O(K) -> heap is created and destroyed and then vector of size K is used.
};

int32_t main()
{
    Solution minHeap;
    int n;
    cin>>n;
    vector<vector<int>> arr(n, vector<int>(n));
    // 11 3 2 1 15 5 4 45 88 96 50 45
    for(int i=0; i<n; i++)for(int j=0; j<n; j++) cin>>arr[i][j];
    // Size of Min Heap
    int k = n;
    vector<int>ans=minHeap.mergeKArrays(arr,k);
    for(auto x: ans)cout<<x<<" ";
    return 0;
}

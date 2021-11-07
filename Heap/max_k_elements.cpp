// “k” largest element in an array
#include <bits/stdc++.h>
using namespace std;

class Solution{
public:	
    // This function pushes top k largest elements in MinHeap
	vector<int> kLargest(int arr[], int n, int k) {
	    priority_queue<int, vector<int>, greater<int>>minH;
        vector<int> ans;
	    for(int i=0; i<n; i++){
	        minH.push(arr[i]);
	        if(minH.size()>k)minH.pop();
	    }
	    while(!minH.empty()){//push elements of minHeap to ans
	        ans.push_back(minH.top());
	        minH.pop();
	    }
        reverse(ans.begin(),ans.end()); // reverse sort ans vector
        return ans;
	}// Time Complexity: O(NLogK) Auxiliary Space: O(K) -> heap is created and destroyed and then vector of size K is used.

};

int32_t main()
{
    Solution minHeap;
    int arr[] = { 11, 3, 2, 1, 15, 5, 4, 45, 88, 96, 50, 45 };
    int size = sizeof(arr) / sizeof(arr[0]);
    // Size of Min Heap
    int k = 3;
    vector<int>ans=minHeap.kLargest(arr,size,k);
    for(auto x: ans)cout<<x<<" ";
    return 0;
}

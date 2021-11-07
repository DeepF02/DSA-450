// Kth smallest and largest element in an unsorted array
// This is same as Kth Smallest of array and matrix folder with a slight variation
// Here we use minHeap or maxHeap to solve
#include <bits/stdc++.h>
using namespace std;

class Solution{
public:	
    // This function pushes top k largest elements in MinHeap
	int kthSmallest(int arr[], int n, int k) {
        priority_queue<int>maxH;
        for(int i=0; i<n; i++){
            maxH.push(arr[i]);
            if(maxH.size()>k)maxH.pop();
        }
        return maxH.top();
	} // Time Complexity: O(NLogK) Auxiliary Space: O(K) -> heap is created and destroyed and then vector of size K is used.

   // Similarly for Kth largest use minHeap;

};

int32_t main()
{
    Solution Heap;
    int arr[] = { 11, 3, 2, 1, 15, 5, 4, 45, 88, 96, 50, 45 };
    int size = sizeof(arr) / sizeof(arr[0]);
    // Size of Min Heap
    int k = 3;
    cout<<Heap.kthSmallest(arr,size,k);
    return 0;
}

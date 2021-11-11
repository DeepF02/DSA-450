// Median in running stream of Integers
#include <bits/stdc++.h>
using namespace std;

class Solution{
public:	
    priority_queue<int>maxHeap, minHeap;
    //Function to insert heap.
    void insertHeap(int &x)
    {
        // we first insert in maxheap if it is empty or val is lower then maxheap top most value
        if(maxHeap.empty() || maxHeap.top()>=x) maxHeap.push(x);
        else minHeap.push(-x);
        
        balanceHeaps();
        
    }
    
    //Function to balance heaps.
    void balanceHeaps()
    {
        //Either both the side of heaps will have equal values or maxHeap will have 1 extra value
        if(maxHeap.size()>minHeap.size()+1){
            minHeap.push(-maxHeap.top());
            maxHeap.pop();
        }
        else if(maxHeap.size()<minHeap.size()){
            maxHeap.push(-minHeap.top());
            minHeap.pop();
        }
        
    }
    
    // Function implementing algorithm to find median so far.
    double getMedian()
    {
        //if total size is even we return avg of top elements of both priority queues.
        if(maxHeap.size()==minHeap.size())
            return (maxHeap.top() + -minHeap.top())/2.0;
            
        //if total size is odd we return avg of top element of maxHeap because it will have one more element then minHeap.
        else return maxHeap.top();
        
    }//Time complexity: O(Nlog(N)) && Auxilary Space: o(N);

    // A utility function to print the array i.e. representation of running stream
    void printStream(int arr[], int n)
    {
        // cout << "Array representation of Heap is:\n";
        for (int i = 0; i < n; ++i){
            insertHeap(arr[i]);
            cout<<floor(getMedian())<<" ";
        };
        cout << "\n";
    }
};

int32_t main()
{
    Solution Heap;
    // int arr[] = { 1, 3, 5, 4, 6, 13, 10, 9, 8, 15, 17 };
    int arr[] = { 5,15,1,3};
    int size = sizeof(arr) / sizeof(arr[0]);
    Heap.printStream(arr, size);

    return 0;
}

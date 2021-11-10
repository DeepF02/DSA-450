// Implemention of Maxheap/MinHeap using arrays and recursion.
#include <bits/stdc++.h>
using namespace std;

class Solution{
public:	
    // To heapify a subtree rooted with node i which is an index in arr[]. N is size of heap
    void heapify(int arr[], int n, int i){
        int largest=i; // Initialize largest as root
        //for 0 based indexing left = 2*i + 1 right = 2*i + 2 
        int left=2*i+1, right=left+1;
        
        if(left<n && arr[left]arr[largest])largest=left; // Check if left element is greater then i
        if(right<n && arr[right]>arr[largest])largest=right;// Check if right element is greater then left
        // *Note* for minHeap sjust reverse the greater then arrow;

        // if left/right were greater then given i then we swap and repeat same process for largest element i
        if(largest!=i){
            swap(arr[i], arr[largest]);
            heapify(arr, n, largest);
        }
    }//Time complexity: O(log(N)) && Auxilary Space: Constant;

    // Function to build a Max-Heap from the given array
    void buildHeap(int arr[], int n){
        
        //We start building heap from n/2-1 cause from n/2 to n-1 index all elements are leaft Node; (for 0 based indexing)
        for(int i=n/2-1; i>=0; i--)heapify(arr, n, i);
        //We don't need to heapify leaf node as there are already individual heap's;

    }//Time complexity: O(N/2) && Auxilary Space: Constant;

    // A utility function to print the array i.e. representation of Heap
    void printHeap(int arr[], int n)
    {
        cout << "Array representation of Heap is:\n";
        for (int i = 0; i < n; ++i) cout << arr[i] << " ";
        cout << "\n";
    }
};

int32_t main()
{
    /* Binary Tree Representation of input array
                    1
                 /     \
                3       5
              /   \    /  \
            4      6  13  10
           / \    / \
          9   8  15 17
    */
    Solution Heap;
    int arr[] = { 1, 3, 5, 4, 6, 13, 10, 9, 8, 15, 17 };
    int size = sizeof(arr) / sizeof(arr[0]);
    Heap.buildHeap(arr, size);//Total Time complexity O(NLog(N))
    Heap.printHeap(arr, size);

    /* Final Heap:
                       17
                    /      \
                 15         13
               /    \      /  \
              9      6    5   10
            / \    /  \
           4   8  3    1
    */

    return 0;
}

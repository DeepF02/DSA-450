// Implemention of Maxheap/MinHeap using arrays and recursion.
#include <bits/stdc++.h>
using namespace std;

class Solution{
private:    
    //Heapify function to maintain heap property.
    void heapify(int arr[], int n, int i)  
    {
      // Your Code Here
      int larg=i;
      int l=2*i+1, r=l+1;
      if(l<n && arr[l]>arr[larg])larg=l;
      if(r<n && arr[r]>arr[larg])larg=r;
      if(larg!=i){
        swap(arr[larg], arr[i]);
        heapify(arr, n, larg);
      }
      else return;
    }//Time complexity: O(N) && Auxilary Space: Constant;

    //Function to build a Heap from array.
    void buildHeap(int arr[], int n)  
    { 
        for(int i=n/2-1; i>=0; i--)heapify(arr, n, i);
    }//Time complexity: O(N/2) && Auxilary Space: Constant;
public:	
    //Function to sort an array using Heap Sort.
    void heapSort(int arr[], int n)
    {
        //step 1 :- Covert given array to heap in O(N) time
        buildHeap(arr, n);
        for(int i=n-1; i>=0; i--){
            //step 2 :- Swap last and first element of array to get higest element at end of the array
            swap(arr[i], arr[0]);
            //step 3:- Heapify array upto ith size i.e n-1 size to get highest element at root again
            heapify(arr, i, 0);
        }//Step 4:- Repeat step 2&3 for all elements of array
    }//Time complexity: O(nlog(n)) && Auxilary Space: Constant;

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
    Solution Heap;
    int arr[] = { 12, 11, 13, 5, 6, 7 };
    int size = sizeof(arr) / sizeof(arr[0]);
    Heap.heapSort(arr, size);
    Heap.printHeap(arr, size);

    return 0;
}

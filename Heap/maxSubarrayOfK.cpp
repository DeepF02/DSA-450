// Maximum of all subarrays of size k. (V.IMP)
#include <bits/stdc++.h>
using namespace std;

class Solution{
public:	
    //Function to find maximum of each subarray of size k.
    vector <int> max_of_subarrays(int *arr, int n, int k)
    {
        /* Method 1: Naive approach //Time Complexity: O(N*K) Auxiliary Space: O(1).
        vector<int>ans;
        for(int i=0; i<=n-k; i++){
            int maxEle=arr[i];
            for(int j=1; j<k; j++) maxEle=max(maxEle, arr[i+j]);
            ans.push_back(maxEle);
        }*/

        // Method 2: Using MaxHeap
        // Time Complexity: O(NLogK) Auxiliary Space: O(K) -> heap is created and destroyed and then vector of size K is used.
        // vector<int>ans;
        // priority_queue<pair<int,int>>maxHeap;
        // bool check[n];//create a arr of type bool of size m
        // memset(check, false, sizeof(check));//this initialises arr check elements to 0
        // for(int i=0; i<k-1; i++) maxHeap.push({arr[i], i});
        // for(int i=0; i+k-1<n; i++){ //iterate array till N-K;
        //     maxHeap.push({arr[i+k-1], i+k-1});
        //     while(check[maxHeap.top().second])maxHeap.pop();
        //     ans.push_back(maxHeap.top().first);
        //     check[i]=true;
        //  }
        
        // Method 2: Using MaxHeap
        // Time Complexity: O(N) Auxiliary Space: O(K) -> heap is created and destroyed and then vector of size K is used.
        vector<int>ans;
        deque<int>dq;
        for(int i=0; i<k; i++){//iterating over first k elements or first window of array.
            // for every element, the previously smaller elements are useless so removing them from deque.
            while(!dq.empty() && dq.back()<arr[i])dq.pop_back();
            dq.push_back(arr[i]);//adding new element at back of deque.   
        }
        //the element at the front of the deque is the largest element of previous window, so adding it to the list.
        ans.push_back(dq.front());
        if(dq.front()==arr[0])dq.pop_front();//removing the elements which are out of this window.
        for(int i=k; i<n; i++){ //iterating over the rest of the elements.
            while(!dq.empty() && dq.back()<arr[i])dq.pop_back();// for every element, the previously smaller elements are useless so removing them from deque.
            dq.push_back(arr[i]);
            ans.push_back(dq.front());//the element at the front of the deque is the largest element of previous window, so adding it to the list.
            if(dq.front()==arr[i-k+1])dq.pop_front();//removing the elements which are out of this window.
        }
        return ans;
    }// Time Complexity: O(NLogK) Auxiliary Space: O(K + N) -> heap is created and destroyed and then vector of size K  & N interger is used.

};

int32_t main()
{
    Solution maxHeap;
    int arr[] = { 11, 3, 2, 1, 15, 5, 4, 45, 88, 96, 50, 45 };
    int size = sizeof(arr) / sizeof(arr[0]);
    // Size of Subarray
    int k = 3;
    vector<int>ans=maxHeap.max_of_subarrays(arr,size,k);
    for(auto x: ans)cout<<x<<" ";
    return 0;
}

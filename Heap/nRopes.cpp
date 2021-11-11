// Connect “n” ropes with minimum cost
#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

class Solution{
public:	
    //Function to return the minimum cost of connecting the ropes.
    ll minCost(ll arr[], ll n) {
        ll ans=0;// Initialize result
        // / Create a min heap of capacity equal to n and put all ropes in it
        priority_queue<ll>minHeap;
        for(ll i=0; i<n; i++)minHeap.push(-arr[i]);
        while(minHeap.size()!=1){
            // Extract two minimum length ropes from min heap and save it in sum
            ll sum=-minHeap.top();
            minHeap.pop();
            sum+=-minHeap.top();
            minHeap.pop();
            ans+=sum;
            // Insert a new rope in min heap with length equal to sum of two extracted minimum lengths
            minHeap.push(-(sum));
        }// Time Complexity: O(NLogN) Auxiliary Space: O(N) -> The space required to store the values in min heap
        
        return ans;
    }

};

int32_t main()
{
    Solution Heap;
    ll arr[] = { 4, 2, 7, 6, 9};
    ll size = sizeof(arr) / sizeof(arr[0]);
    cout<<Heap.minCost(arr,size);
    return 0;
}

// find all pairs on integer array whose sum is equal to given number
#include <bits/stdc++.h>
using namespace std;

class Solution{

    // Function to returns number of pairs in arr[] with sum equal to 'K'
    public:
    int getPairsCount(int arr[], int n, int k) {
        // code here
        int cnt=0;
        unordered_map<int, int>mp;// Store counts of all elements in map mp
        for(auto i=0; i<n; i++){
            int x=k-arr[i];
            if(mp[x])cnt+=mp[x];
            mp[arr[i]]++;// iterate through each element and increment mp
        }
        return cnt;
    }// Time Complexity: O(N) && Auxiliary Space: O(N)
};

int32_t main()
{
    int arr[5] = { 1, 5, 7, -1, 5};
    Solution ans;
    cout << "Count of pairs is "
         << ans.getPairsCount(arr, 5, 6);
    return 0;
}
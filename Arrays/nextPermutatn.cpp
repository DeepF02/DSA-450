//Next Permutation
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> nextPermutation(int n, vector<int> arr){
        // code here
        int k=-1;
        for(int i=n-1; i>0; i--){
            if(arr[i]>arr[i-1]){
                k=i-1;
                break;
            }
        }
        if(k==-1){
            reverse(arr.begin(), arr.end());
            return arr;
        }
        for(int i=n-1; i>=0; i--){
            if(arr[k]<arr[i]){
                swap(arr[k], arr[i]);
                reverse(arr.begin()+k+1, arr.end());
                return arr;
            }
        }
        return arr;
    }// Time Complexity: O(N) && Auxiliary Space: O(1)
};

int32_t main()
{
    Solution Array;
    vector<int> arr = {5, 8, 10, 20}; 
    vector<int> ans = Array.nextPermutation(4, arr);
    for(auto x:ans) cout << x<<" "; 
    return 0;
}
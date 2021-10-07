// Smallest Subarray with sum greater than a given value
#include <bits/stdc++.h>
using namespace std;

class Solution{
  public:
    int smallestSubWithSum(int arr[], int n, int x)
    {
        int sum=0, i=0, j=0, ans=INT_MAX;
        while(i<n && j<n){
            sum+=arr[j];
            if(sum>x){
                sum-=(arr[i]+arr[j]);
                ans=min(ans, j-i+1);
                i++;
            }
            else j++;
        }
        return ans;
    }
};

int32_t main()
{
    int n, x;
    cin>>n>>x;
    int arr[n];
    for(int i=0; i<n; i++) cin>>arr[i];
    Solution ans;
    cout<<ans.smallestSubWithSum(arr, n, x);
    return 0;
}
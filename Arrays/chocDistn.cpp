// Chocolate Distribution problem
#include <bits/stdc++.h>
#define ll long long int
using namespace std;

class Solution{
    public:
    ll findMinDiff(vector<ll> &a, ll n, ll m){
        //code
        if(n<m)return -1;
        sort(a.begin(), a.end());
        ll j=m-1, ans=INT_MAX;
        for(int i=0; i<n; i++){
            if(j>=n && j-i<m)break;
            ans=min(ans, abs(a[i]-a[j]));
            j++;
        }
        return ans;
    }   
};

int32_t main()
{
    ll n, m;
    cin>>n>>m;
    vector<ll> arr(n);
    for(int i=0; i<n; i++) cin>>arr[i];
    Solution ans;
    cout<<ans.findMinDiff(arr, n, m);
    return 0;
}
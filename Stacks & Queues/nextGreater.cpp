// Find the next Greater element
#include <bits/stdc++.h>
using namespace std;

#define ll long long int

class Solution
{
    public:
    //Function to find the next greater element for each element of the array.
    vector<ll> nextLargerElement(vector<ll> arr, int n){
        stack<ll>s;
        vector<ll>ans(n);
        for(int i=n-1; i>=0; i--){
            while(!s.empty() && arr[i]>=s.top()) s.pop();
            if(s.empty())ans[i]=-1;
            else ans[i]=s.top();
            s.push(arr[i]);
        }
        return ans;
    }
};

int32_t main()
{
    Solution ans;
    int n;
    cin>>n;
    vector<ll>arr(n);
    for (ll i = 0; i < n; i++)
        cin>>arr[i];
    
    // while(n--)arr.push_back(n);
    vector<ll>res = ans.nextLargerElement(arr, n);
    for(ll x:res) cout<<x<<" ";
    return 0;
}
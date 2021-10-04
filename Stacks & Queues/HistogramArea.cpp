// Largest rectangular Area in Histogram
#include <bits/stdc++.h>
using namespace std;
#define ll long long int

class Solution {
public:
    vector<ll>previousSmaller(vector<ll> arr, int n){
        stack<int>s;
        vector<ll>prevSmall(n);
        for(int i=0; i<n; i++){
            while(!s.empty() && arr[s.top()]>=arr[i])s.pop();
            if(s.empty())prevSmall[i]=-1;
            else prevSmall[i]=s.top();
            s.push(i);
        }
        return prevSmall;
    }
    vector<ll>nextSmaller(vector<ll> arr, int n){
        stack<int>s;
        vector<ll>nextSmall(n);
        for(int i=n-1; i>=0; i--){
            while(!s.empty() && arr[s.top()]>=arr[i])s.pop();
            if(s.empty())nextSmall[i]=n;
            else nextSmall[i]=s.top();
            s.push(i);
        }
        return nextSmall;
    }
    ll getMaxArea(vector<ll> arr, int n)
    {
        ll area=0;
        vector<ll>prevSmall = previousSmaller(arr, n);
        vector<ll>nextSmall = nextSmaller(arr, n);
        for(int i=0; i<n; i++){
            ll temp=(nextSmall[i]-prevSmall[i]-1)*arr[i];
            area=max(area, temp);
        }
        return area;
    }
};

int32_t main()
{
    Solution ans;
    int n;
    cin>>n;
    vector<ll>arr(n);
    for (int i = 0; i < n; i++)
        cin>>arr[i];
    ll area = ans.getMaxArea(arr, n);
    cout<<area<<endl;
    return 0;
}
// Find the next Smaller element
#include <bits/stdc++.h>
using namespace std;

#define ll long long int

class Solution {
public:
    vector<int> nextSmallerElement(vector<int>& v) {
        stack<int>s;
        int n=v.size();
        vector<int>ans(n);
        ans[n-1]=-1;
        s.push(v[n-1]);
        for(int i=n-2; i>=0; --i){
            while(!s.empty() && v[i]<s.top())s.pop();
            if(s.empty())ans[i]=-1;
            else ans[i]=s.top();
            s.push(v[i]);
        }
        return ans;
    }
};

int32_t main()
{
    Solution ans;
    int n;
    cin>>n;
    vector<int>arr(n);
    for (int i = 0; i < n; i++)
        cin>>arr[i];
    vector<int>res = ans.nextSmallerElement(arr);
    for(int x:res) cout<<x<<" ";
    return 0;
}
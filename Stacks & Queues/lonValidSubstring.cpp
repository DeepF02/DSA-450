// Length of the Longest Valid Substring
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int findMaxLen(string s) {
        // code here
        stack<int>sk;
        sk.push(-1);
        int ans=0;
        for(int i=0; i<s.size(); i++){
            if(s[i]=='(')sk.push(i);
            else{
                if(!sk.empty())sk.pop();
                if(!sk.empty())ans=max(ans,i-sk.top());
                else sk.push(i);
            }
        }
        return ans;
    }
};

int32_t main()
{
    string s;
    cin>>s;
    Solution ans;
    cout<<ans.findMaxLen(s);
    return 0;
}
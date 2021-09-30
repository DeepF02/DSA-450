//Check the expression has valid or Balanced parenthesis or not.
#include <bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    //Function to check if brackets are balanced or not.
    bool ispar(string x)
    {
        // Your code here
        stack<char>s;
        bool flag=false;
        for(int i=0; i<x.size(); i++){
            if(x[i]=='(' || x[i]=='[' || x[i]=='{')s.push(x[i]);
            else{
                if(x[i]==')'){
                    if(!s.empty() && s.top()=='(')s.pop();
                    else return flag;
                }
                else if(x[i]==']'){
                    if(!s.empty() && s.top()=='[')s.pop();
                    else return flag;
                }
                else if(x[i]=='}'){
                    if(!s.empty() && s.top()=='{')s.pop();
                    else return flag;
                }
            }
        }
        if(s.empty())flag=true;
        return flag;
    }

};
int32_t main()
{
    Solution obj;
    string s;
    cin>>s;
    cout<<obj.ispar(s);
    return 0;
}
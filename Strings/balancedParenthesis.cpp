//Balanced Parenthesis problem.[Imp]
// This is same as parenthesis.cpp in Stacks folder.
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
        for(auto c:x){
            if(c=='(' || c=='[' || c=='{')s.push(c);
            else{
                if(c==')'){
                    if(!s.empty() && s.top()=='(')s.pop();
                    else return flag;
                }
                else if(c==']'){
                    if(!s.empty() && s.top()=='[')s.pop();
                    else return flag;
                }
                else{
                    if(!s.empty() && s.top()=='{')s.pop();
                    else return flag;
                }
            }
        }
        if(s.empty())flag=true;
        return flag;
    }//Time Complexity: O(n) 
    // Auxiliary Space: O(n) for stack. 
};
int32_t main()
{
    Solution obj;
    string s;
    cin>>s;
    (obj.ispar(s))?cout<<"Balanced\n":cout<<"Not balanced\n";
    return 0;
}
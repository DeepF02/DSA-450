//All c++ std template
#include <bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    //Function to check wheter the expression is an operator.
    bool isValid(char s){
        return (s=='*'|| s=='/' || s=='+' || s=='-')?true:false;
    }
    //Function to evaluate a postfix expression.
    int evaluatePostfix(string S)
    {
        // We Create a stack to perform our operation
        stack<int>s;
        for(int i=0; i<S.size(); i++){
            //if current character is an operand, we push it to the stack.
            if(!isValid(S[i])) s.push(S[i]-'0');
            //else current character is an operator.
            else{
                 //we pop and store the values of first two elements of stack.
                int OP1=s.top(); s.pop();
                int OP2=s.top(); s.pop();
                //we perform required operation and push the result in stack.
                if(S[i]=='*')s.push(OP2*OP1);
                else if(S[i]=='/')s.push(OP2/OP1);
                else if(S[i]=='+')s.push(OP2+OP1);
                else s.push(OP2-OP1);
            }
        }
        //returning the top element of the stack.
        return s.top();
    }
};

int32_t main()
{
    string s;
    cin>>s;
    Solution ans;
    cout<<ans.evaluatePostfix(s);
    return 0;
}

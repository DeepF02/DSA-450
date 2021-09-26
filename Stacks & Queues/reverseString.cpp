//All c++ std template
#include <bits/stdc++.h>
using namespace std;

//Reserving string using stack DS.
char* reverse(char *S, int len)
{
    //code here
    stack<int>s;
    for(int i=0; i<len; i++){
        s.push(S[i]);
    }
    for(int i=0; i<len; i++){
        S[i]=s.top();
        s.pop();
    }
    return S;
}
int32_t main()
{
    char str[] = "abc";
    int len=strlen(str);
    reverse(str, len);
    cout<<"Reversed string is "<< str;

    return 0;
}
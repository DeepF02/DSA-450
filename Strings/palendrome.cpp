// Check whether a String is Palindrome or not
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPalindrome(string S)
	{
	    string ans = S;
	    reverse(S.begin(), S.end());
	    if(S==ans)return true;
	    return false;
	}
};

int32_t main(){
    string s;
    cin>>s;
    Solution ans;
    cout<<ans.isPalindrome(s);
    return 0;
}
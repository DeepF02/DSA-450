// Check whether a String is Palindrome or not
#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    // Recursive Method to check palendrome
    bool check(string& s, int n, int i){
        if(i>n/2-1) return 1;
        if(s[n-i-1]!=s[i])return 0;
        return check(s, n, ++i);
    }
public:
    bool isPalindrome(string S)
	{
        // Method 1: Using STL reverse
	    // string ans = S;
	    // reverse(S.begin(), S.end());
        // return if(S==ans)?true:false;
        
        // Method 2: Using Recursion
        return check(S, S.size(), 0);
	}
};

int32_t main(){
    string s;
    cin>>s;
    Solution ans;
    cout<<ans.isPalindrome(s);
    return 0;
}
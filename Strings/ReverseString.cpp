// Reverse a String
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Method 1: Using Iteration
    void reverseString(vector<char> &s)
    {
        int n = s.size();
        for (int i = 0; i < n / 2; i++)
        {
            swap(s[i], s[n - i - 1]);
        }
    }
    
    // Method 2: Using Recursive 2 pointer swap
    // void reverse(string& s, int n, int i){
    //     if(n<=i) return;
    //     swap(s[n], s[i]);
    //     reverse(s, n-1, ++i);
    // }

    // Method 3: Using Recursive single pointer swap
    void reverse(string &s, int n, int i)
    {
        if (i > n / 2 - 1)
            return;
        swap(s[n - i - 1], s[i]);
        reverse(s, n, ++i);
    }

    // Method 4: Using Parameterized Recursive single pointer swap
    // string reverse(string& s, int i, string& ans){
    //     if(i==s.size()) return ans;
    //     reverse(s, ++i, ans);
    //     ans.push_back(s[i]);
    //     return ans;
    // }
};

int32_t main()
{
    int n;
    cin >> n;
    vector<char> s(n);
    for (int i = 0; i < n; i++)
        cin >> s[i];
    Solution ans;
    ans.reverseString(s);
    for (int i = 0; i < n; i++)
        cout << s[i] << " ";
    return 0;
}
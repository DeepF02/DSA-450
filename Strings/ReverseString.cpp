#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void reverseString(vector<char>& s) {
        int n=s.size();
        for(int i=0; i<n/2; i++){
            swap(s[i],s[n-i-1]);
        }
    }
};

int32_t main(){
    int n;
    cin>>n;
    vector<char>s(n);
    for(int i=0; i<n; i++)
        cin>>s[i];
    Solution ans;
    ans.reverseString(s);
    for(int i=0; i<n; i++)
        cout<<s[i]<<" ";
    return 0;
}
// Queue based approach or first non-repeating character in a stream.
#include <bits/stdc++.h>
using namespace std;

class Solution 
{
    public:

    //Function to find first non-repeating characters in a stream.
    //Method 1: using Queue & HashMap approach
    string FirstNonRepeating(string s) 
    {
        // code here
        queue<int>q; //We craete a queue and store all the char only once as they appear in the stream
        unordered_map<char, int>mp; //We use map to get frequency of char appearing in the stream
        string ans=""; // To store the output string 
        for(auto ch:s){ // We traverse through the stream
            if(!mp[ch])q.push(ch); //If the char appear's first time e push it in the straeam;
            mp[ch]++; //We increment char frequency in map
            while(!q.empty() && mp[q.front()]!=1)q.pop(); //If frequency of char at the front of q is higher then 1 we pop it till its 1
            (!q.empty())?ans+=q.front():ans+='#'; //If q is "#" else we psuh top char of queue;
        }
        return ans;
    }// Time complexity = O(N), space complexity = O(2N), N is no. of char of string 

    //Method 2 through two pointer approach
    // string FirstNonRepeating(string s) 
    // {
    //     queue<int>q;
    //     unordered_map<char, int>mp;
    //     string ans="";
    //     return ans;
    // }// Time complexity =O(n), space complexity = O(1)
};

int32_t main()
{
    Solution queue;
    string s;
    cin>>s;
    cout<<"Output of First non-repeating characters is : "<<queue.FirstNonRepeating(s);
    return 0;
}

// Input: A = "aabc"
// Output: "a#bb"

// Input: A = pqimpqysf
// Output: ppppqiiii
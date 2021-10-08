// Best Time to Buy and Sell Stock leetcode prob
#include <bits/stdc++.h>
using namespace std;

class Solution 
{
    public:
    //Function to find if there is a celebrity in the party or not.
    
    //Method 1 through StacK approach
    // Time complexity = O(n) ~ O(3(n-1)) , space complexity = O(n) 
    int celebrity(vector<vector<int> >& M, int n) 
    {
        // code here
        stack<int>s;
        int a=0, b=n-1, temp=0;
        bool flag=0;
        for(int i=0; i<n; i++)s.push(i);
        while(!s.empty()){
            temp=s.top();
            s.pop();
            if(!s.empty() && M[s.top()][temp]==1){
                s.pop();
                s.push(temp);
            }
        }
        for(int i=0; i<n; i++){
            if(M[temp][i]==1)return -1;
            if(M[i][temp]==1)flag=true;
        }
        return (flag)?temp:-1;
    }
    //Method 2 through two pointer approach
    // Time complexity =O(n), space complexity = O(1)
    // int celebrity(vector<vector<int> >& M, int n) 
    // {
    //     //initializing two pointers for two corners.
    //     int a = 0;
    //     int b = n - 1;
        
    //     //we keep moving till the a<b. 
    //     while (a < b) {
    //         if (M[a][b])
    //             a++;
    //         else
    //             b--;
    //     }
        
    //     //checking if a is actually a celebrity or not.
    //     for (int i = 0; i < n; i++)
    //     {
    //         //if any person doesn't know a or a knows any person, we return -1. 
    //         if ( (i != a) && (M[a][i] || !M[i][a]) )
    //             return -1;
    //     }
    //     //if we reach here a is celebrity so we retun a.
    //     return a;
    // }
};

int32_t main()
{
    int n;
    cin>>n;
    vector<vector<int>> party(n, vector<int>(n));
    for(int i=0; i<n; i++) for(int j=0; j<n; j++) cin>>party[i][j];
    Solution ans;
    cout<<ans.celebrity(party, n);
    return 0;
}
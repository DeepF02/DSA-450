// 0/1 Knapsack Problem
#include <bits/stdc++.h>
using namespace std;

int t[1001][1001];// we define a global Matrix of n*W of size equals to given constraints;

class Solution
{
    public:
    //Method 1: Recusion + Memoization
    //Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int W, int wt[], int val[], int n) 
    { 
       // Your code here
       // Method 1: Memoization;
    //    memset(t, -1, sizeof (t)); //Initialize matriz by -1;
    //    return helperSack(W, wt, val, n);

       // Method 2: Top-Down Appoarch
       // Time Complexity: O(N*W). As redundant calculations of states are avoided.
       //Auxiliary Space: O(N*W). The use of 2D array data structure for storing intermediate states
       for(int i=0; i<n+1; ++i){
           for(int j=0; j<W+1; ++j){
               //Initializing the matrix same as recursion Base condition
               if(i==0 || j==0)t[i][j]=0;
           }
       }
       for(int i=1; i<n+1; ++i){
           for(int j=1; j<W+1; ++j){
               //Geting the max value if wt is under capacity
               if(wt[i-1]<=j)t[i][j]=max(val[i-1] + t[i-1][j-wt[i-1]], t[i-1][j]);
               else t[i][j]=t[i-1][j]; //If weight is over capacity we simply store here the same value
           }
       }
       return t[n][W];// returning the maximum value of knapsack
    }
    int helperSack(int W, int wt[], int val[], int n){
       if(n==0 || W==0) return 0; //Base condition
       if(t[n][W]!=-1)return t[n][W];
       // If items weight is less then equals to Capacity of knapSack then we decide to whether store it in kanpsack or not
       if(wt[n-1]<=W){
           // Store the value of function call stack in table before return
           t[n][W]=max(val[n-1] + helperSack(W-wt[n-1], wt, val, n-1), helperSack(W, wt, val, n-1));// Returns the value of maximum profit
           // Return value of table after storing
           return t[n][W];
       }
       // If items weight is more then Capacity of knapSack we can't store it in kanpsack
       else return t[n][W]=helperSack(W, wt, val, n-1);
    }// Time Complexity: O(N*W). As redundant calculations of states are avoided.
    //Auxiliary Space: O(N*W). The use of 2D array data structure for storing intermediate states-:
};

int32_t main()
{
    Solution DP;
    int val[] = { 60, 100, 120 };
    int wt[] = { 10, 20, 30 };
    int W = 50; // Weight/Capacity of knapsack
    int n = sizeof(wt) / sizeof(wt[0]); // No. of items
    // Function call
    cout << "Maximum value we can obtain = "<< DP.knapSack(W, wt, val, n);
   
   return 0;
}
// Subset Sum Problem
#include <bits/stdc++.h>
using namespace std;

int t[1001][1001]; // we define a global Matrix of n*W of size equals to given constraints;

class Solution
{
private: 
    // Function toCheck if possible subset with given sum is possible or not   
    bool subsetSum(vector<int> arr, int n, int sum)
    {
        // Method 1: Recusion + Memoization;
        // memset(t, -1, sizeof(t)); // Initialize matriz by -1;
        // // If the sum is zero it means we got our expected sum
        // if (sum == 0) return 1;
        // if (n <= 0) return 0;

        // // If the value is not -1 it means it already call the function with the same value it will save our from the repetition.
        // if (t[n - 1][sum] != -1) return t[n - 1][sum];

        // // Here we do two calls because we don't know which value is full-fill our criteria that's why we doing two calls
        // if (arr[n - 1] <= sum) return t[n - 1][sum] = subsetSum(arr, n - 1, sum) || subsetSum(arr, n - 1, sum - arr[n - 1]);
               
        // // if the value of a[n-1] is greater than the sum. we call for the next value                      
        // else return t[n - 1][sum] = subsetSum(arr, n - 1, sum);
            
        // Method 2: Top-Down Appoarch
        bool T[n + 1][sum + 1]; // we define a table
        // Same as 0/1 kanpsack we initialize this table
        for (int i = 0; i <= n; ++i)
        {
            for (int j = 0; j <= sum; ++j)
            {
                // If sum is 0 then there can always be a empty subset of sum 0 hence we initialze true
                if (j == 0)
                    T[i][j] = 1;
                // If arr size is 0  and sum is >0 then we can never have a subset given sum hence we initialze false
                else if (i == 0)
                    T[i][j] = 0;
            }
        }
        // This is same as 0/1 kanpsack only wt[] is arr[], W is sum and max is Or(||);
        // Fill the subset table in bottom up manner
        for (int i = 1; i <= n; ++i)
        {
            for (int j = 1; j <= sum; ++j)
            {
                if (arr[i - 1] <= j)
                    T[i][j] = T[i - 1][j] || T[i - 1][j - arr[i - 1]]; // arr element is under sum we can check for this element
                else
                    T[i][j] = T[i - 1][j]; // else we move to next element and mark this same as table element in lower col block
            }
        }
        // size of arr and sum block in table will store the final ans same as 0/1 knapsack
        return T[n][sum];
    } // Time Complexity: O(N*(Sum/2)). As redundant calculations of states are avoided.
    // Space Complexity: O(N*(Sum/2)). The use of 2D array data structure for storing intermediate states-:
public:
    // Function to return True if arr can be divided into two equal subsets of there sum each.
    bool canPartition(vector<int> &arr)
    {
        // We find Sum of all elements of the array
        int sum = 0;
        for (auto it : arr)
            sum += it;
        // If Sum is odd then we can never get 2 subsets of equal sum as odd no. can't be divided into equal parts
        if (sum % 2 != 0)
            return 0;
        // If sum is even the problems becomes same as Suset sum of gfg
        return subsetSum(arr, arr.size(), sum / 2);
    }
};

int32_t main()
{
    Solution DP;
    vector<int> arr = {60, 100, 120, 80};
    // Function call
    (DP.canPartition(arr))?cout << "There exists a subset with given sum\n":cout<<"No subset exists with given sum\n";
    return 0;
}
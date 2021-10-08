// Best Time to Buy and Sell Stock leetcode prob
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minP=prices[0], maxP=0;
        for(int i=1; i<prices.size(); i++){
            minP=min(minP,prices[i]);
            maxP=max(maxP, prices[i]-minP);
        }
        return maxP;
    }
};

int32_t main()
{
    int n;
    cin>>n;
    vector<int> prices(n);
    for(int i=0; i<n; i++) cin>>prices[i];
    Solution ans;
    cout<<ans.maxProfit(prices);
    return 0;
}
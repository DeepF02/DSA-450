// Merge Intervals
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        int n = intervals.size();
        vector<vector<int>> ans;
        if (n < 2)
            return intervals;
        sort(intervals.begin(), intervals.end());
        for (int i = 1; i < n; i++)
        {
            //if (intervals[i - 1][1] >= intervals[i][0])
            //   (intervals[i - 1][1] <= intervals[i][1]) ? intervals[i] = {intervals[i - 1][0], intervals[i][1]} : intervals[i] = {intervals[i - 1][0], intervals[i - 1][1]};
            if (intervals[i - 1][1] >= intervals[i][0]){
                intervals[i][0] = intervals[i - 1][0];
                intervals[i][1] = max(intervals[i][1], intervals[i - 1][1]);
            }
            else ans.push_back(intervals[i - 1]);
        }
        ans.push_back(intervals[n - 1]);
        return ans;
    }
};
int main()
{
    int n;
    cin >> n;
    vector<vector<int>> nums(n, vector<int>(2));
    for (int i = 0; i < n; i++)
        cin >> nums[i][0] >> nums[i][1];
    Solution vec;
    nums = vec.merge(nums);
    cout << "[";
    for (int i = 0; i < nums.size(); i++)
        cout << "[" << nums[i][0] << " " << nums[i][1] << "]";
    cout << "]\n";
    return 0;
}
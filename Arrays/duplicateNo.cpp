//find duplicate in an array of N+1 Integers
#include <bits/stdc++.h>
#define ll long long int
using namespace std;

class solution
{
public:
    int findDuplicate(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> freq(n);
        fill(freq.begin(), freq.end(), 0);
        for (auto x : nums)
        {
            freq[x]++;
        }
        for (int i = 0; i < n; i++)
        {
            if (freq[i] > 1)
                return i;
        }
        return -1;
    }
};

void inputVector(vector<int> &v, int n)
{
    int temp;
    for (int i = 0; i <= n; i++)
    {
        cin >> temp;
        v.push_back(temp);
    }
}

int32_t main()
{
    int n;
    cin >> n;
    vector<int> nums;
    inputVector(nums, n);
    solution solve;
    cout << solve.findDuplicate(nums) << endl;
    return 0;
}
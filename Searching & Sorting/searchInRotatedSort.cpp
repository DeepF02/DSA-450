// Search in a rotated sorted array
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n=nums.size();
        int l=0, r=n-1;
        while(l<=r){
            int mid =l+(r-l)/2;
            int camparator;
            // Checking if both target and nums[mid] are on same side.
            if((target < nums[0] && nums[mid] < nums[0]) || (target>=nums[0] && nums[mid]>=nums[0])) camparator=nums[mid];
            else{
                // Trying to figure out where nums[mid] is and making comparator as -INF or INF
                if(target<nums[0])camparator=INT_MIN;//basically we make every element below till mid+1 as -INFINITFY
                else camparator=INT_MAX;//basically we make every element after mid-1 as INFINITY
            }
            if(target == camparator) return mid;
            else if(target > camparator) l = mid+1;
            else r = mid-1;
        }
        return -1;
    }
};

int32_t main()
{
    int target, n;
    cin>>n>>target;
    vector<int> nums(n);
    for(int i=0; i<n; i++)cin>>nums[i];
    Solution ans;
    cout<<ans.search(nums, target);

    return 0;
}
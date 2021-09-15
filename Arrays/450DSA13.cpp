#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals){
        int n=intervals.size(), i;
        // vector<vector<int>>::iterator it1, it2;
        vector<vector<int>>answer;
        // it1=intervals.begin();
        // it2=intervals.end();
        vector<int>x, y;
        // if(n<2) return intervals;
        sort(intervals.begin(), intervals.end());
        for(i=1; i<n; i++){
            x=intervals[i-1];
            y=intervals[i];
            if(x[1]>=y[0]){ 
                (x[1]<=y[1])?intervals[i]={x[0], y[1]}:intervals[i] = {x[0], x[1]};
            } else{
                answer.push_back(intervals[i-1]);
            }
        }
        answer.push_back(intervals[i-1]);
        return answer;
    }
};
// class Solution {
// public:
//     vector<vector<int>> merge(vector<vector<int>>& intervals) {
//         vector<vector<int>> res;
//         int n = intervals.size();
//         sort(intervals.begin(), intervals.end());
//         int i;
//         for(i = 1; i < n; ++i) {
//             if(intervals[i-1][1] >= intervals[i][0] ) {
//                 intervals[i][0] = intervals[i-1][0];
//                 intervals[i][1] = max(intervals[i][1], intervals[i-1][1]);
//             } else {
//                 res.push_back(intervals[i-1]);
//             }
//         }
//         res.push_back(intervals[i-1]);
//         return res;
//     }
// };
void inputVecVector(vector<vector<int>>& nums, int n)
{
    vector<int>temp;
    int tempElement;
    for (int i = 0; i <n; i++)
    {
        for(int i=0; i<2; i++){
            cin>>tempElement;
            temp.push_back(tempElement);
        }
        nums.push_back(temp);
    }
}
int main()
{
    int n;
    cin>>n;
    vector<vector<int>> nums;
    vector<vector<int>> ans;
    inputVecVector(nums, n);
    Solution vec;
    ans=vec.merge(nums);

    for (int i = 0; i <ans.size(); i++)
    {
        cout<<"[";
        for(int j=0; j<ans[i].size(); j++){
            if(j%2==0) cout<<"[";
            cout<<ans[i][j]<<" ";
            if(j%2==1)cout<<"]";
        }
        cout<<"]\n";
    }
    return 0;
}
// 3
// 1 5
// 2 4
// 7 9
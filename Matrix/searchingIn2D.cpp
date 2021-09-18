#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int r=matrix.size();
        int c=matrix[0].size();
        for(int i=0; i<r; i++){
            for(int j=0; j<c; j++)if(matrix[i][j]==target) return true;        
        }
        // int i=0, j=c-1;
        // int m =(i+j)/2;
        // while(i<j){
        //     if(matrix[i])
        // }
        return false;
    }
};

int32_t main()
{
    int r, c;
    cin >> r >> c;
    vector<vector<int>> matrix(r);
    for(int i=0; i<r; i++){
        matrix[i].assign(c, 0);
        for(int j=0; j<c; j++){
            cin>>matrix[i][j];
        }
    }
    int target;
    cin>>target;
    Solution ans;
    cout<<ans.searchMatrix(matrix, target);
    // for(int i=0; i<result.size(); i++){
    //     cout<<result[i]<<" ";
    // }

    return 0;
}
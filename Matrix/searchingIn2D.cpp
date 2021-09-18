#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        //Method 1 Time complexity O(n*m)
        // int r=matrix.size();
        // int c=matrix[0].size();
        // for(int i=0; i<r; i++){
        //     for(int j=0; j<c; j++)if(matrix[i][j]==target) return true;        
        // }

        // Method 2 Time complexity O(log(n))
        int r=matrix.size(), c=matrix[0].size(), i=0, j1=0, j2=c, m;
        while(j1<j2 && i<r){
            if(target>matrix[i][c-1]){
                if(i<r){
                    ++i;
                    continue;
                }
                else break;
            }
            m =(j1+j2)/2;
            if(matrix[i][m]==target)return true;
            else if (matrix[i][m]>target){
                if(m==j2)break;
                j2=m;
            }
            else if (matrix[i][m]<target){
                if(m==j1)break;
                j1=m;
            }
        }
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
    return 0;
}

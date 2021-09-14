#include <bits/stdc++.h>
#define ll long long int
using namespace std;

class Solution
{
public:
    vector<int> spirallyTraverse(vector<vector<int>> matrix, int r, int c)
    {
        // code here
        vector<int> ans;
        int i = 0, j = 0, it = 0, x = 0, y = 0;
        (r % 2 == 0) ? (it = r / 2) : (it = (r / 2 + 1));
        while (it--)
        {
            i = x;
            if (ans.size() == c * r)
                break;
            for (j = y; j < (c - y); j++)
            {
                ans.push_back(matrix[i][j]);
            }
            if (ans.size() == c * r)
                break;
            j = c - y - 1;
            for (i = (x + 1); i < (r - x); i++)
            {
                ans.push_back(matrix[i][j]);
            }
            if (ans.size() == c * r)
                break;
            i = r - x - 1;
            for (j = (c - y - 2); j >= y; j--)
            {
                ans.push_back(matrix[i][j]);
            }
            if (ans.size() == c * r)
                break;
            j = y;
            for (i = (r - x - 2); i > x; i--)
            {
                ans.push_back(matrix[i][j]);
            }
            x++;
            y++;
        }
        return ans;
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
    Solution ans;
    vector<int> result=ans.spirallyTraverse(matrix, r, c);
    for(int i=0; i<result.size(); i++){
        cout<<result[i]<<" ";
    }

    return 0;
}
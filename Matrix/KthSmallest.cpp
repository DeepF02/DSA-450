// Kth smallest element in a row-cpumn wise sorted matrix
#include <bits/stdc++.h>
using namespace std;

int kthSmallest(int mat[][4], int n, int k)
{
    priority_queue<int>maxH;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            maxH.push(mat[i][j]);
            if(maxH.size()>k)maxH.pop();
        }
    }
    return maxH.top();
} // Time Complexity: O(K*Log(N)) & Auxiliary Space: O(N)

int32_t main()
{
    int mat[4][4] = {
        // { 10, 20, 30, 40 },
        // { 15, 25, 35, 45 },
        // { 25, 29, 37, 48 },
        // { 32, 33, 39, 50 },
        {16, 28, 60, 64},
        {22, 41, 63, 91},
        {27, 50, 87, 93},
        {36, 78, 87, 94},
    };
    cout << "7th smallest element is "<< kthSmallest(mat, 4, 7);

    return 0;
}

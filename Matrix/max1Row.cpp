// Find row with maximum no. of 1's
#include <bits/stdc++.h>
using namespace std;
#define ll long long int

class Solution{
public:
	int rowWithMax1s(vector<vector<int> > arr, int n, int m) {
	    int ans=0, minCol=INT_MAX, currCol=INT_MAX;
	    bool flag=0;
	    for(int i=0; i<n; i++){
	        for(int j=0; j<m; j++){
	            if(arr[i][j]==1){
	                flag=1;
	                currCol=j;
	                break;
	            }
	        }
	        if(currCol<minCol)ans=i;
	        minCol=min(minCol, currCol);
	    }
	    return (flag==1)? ans: -1;
	}

};

int32_t main()
{
    Solution ans;
    int n, m;
    cin>>n>>m;
    vector<vector<int>>arr(n, vector<int>(m));
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++) cin>>arr[i][j];
    }
    cout<<ans. rowWithMax1s(arr, n, m)<<endl;
    return 0;
}
//Median of 2 sorted arrays of different size
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& v1, vector<int>& v2) {
        // if(v2.size()<v1.size()) swap(v2,v1);
		int m=v1.size(), n=v2.size(), l=0, r=m;
        while(l<=r){
            int med1   = (l+r)/2;
            int med2   =  n - med1;
            int left1  = ((med1)==0) ? INT_MIN : v1[med1-1];
            int left2  = ((med2)==0) ? INT_MIN : v2[med2-1];
            int right1 = ((med1)>=m) ? INT_MAX : v1[med1];
            int right2 = ((med2)>=n) ? INT_MAX : v2[med2];
            if(left2<=right1 && left1<=right2)
                return (max(left1,left2) + min(right1, right2))/2.0;
            else if(left2>right1) l=med1+1;
            else r=med1-1;
        } 
        return 0;
    }
};

int32_t main()
{
    Solution ob;
    vector<int> ar1 = {5, 8, 10, 20}; 
    vector<int> ar2 = {5, 8, 10, 20}; 
    cout << ob.findMedianSortedArrays(ar1, ar2); 
    return 0;
}
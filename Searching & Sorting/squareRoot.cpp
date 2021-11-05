//square root of an integer
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int countSquares(int N) {
        /*C++ Stl method
        // return ceil(sqrt(N))-1; */
        
        // one method is to keep and iterator i increment it till its sqrt is less then equal to N

        // By Binary Search algo Method
        //Base Condition
        if(N==0 || N==1)return N;
        int start=1, end=N/2, ans=0;
        while(start<=end){
            long long int mid=start + (end-start)/2;
            long long  int sqrt=mid*mid;
            if(sqrt==N)return mid-1;
            // Since we need floor, we update answer when mid*mid is smaller than N, and move closer to sqrt(N)
            if(sqrt<=N){
                start=mid+1;
                ans=mid;
            }
            else end=mid-1;
        }
        return ans;
    }
    // Time complexity: O(log n). ->  The time complexity of binary search is O(log n).
    // Space Complexity: O(1). -> Constant extra space is needed.
};

int32_t main()
{
    Solution ans;
    int n;
    cin>>n;
    cout<<ans.countSquares(n)<<endl;
    cout<<ceil(sqrt(n))-1;//to check our ans is correct
    return 0;
}

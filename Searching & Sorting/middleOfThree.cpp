// Maximum and minimum of an array using minimum number of comparisons
#include <bits/stdc++.h>
using namespace std;

class Solution 
{
    public:
    //Function to get minimum & maximum element in array.
    int middle(int A, int B, int C){
        //code here//Position this line where user code will be pasted.
        // if(A>B){
        //     if(A<C)return A;
        //     else if(B>C)return B;
        //     else return C;
        // }
        // else if(B>A){
        //     if(A>C)return A;
        //     else if(B<C)return B;
        //     else return C;
        // }
        int mn =min(min(A,B), C);
        int mx =max(max(A,B), C);
        return A+B+C-mn-mx;
    }// Time Complexity: O(1) && Auxiliary Space: O(1)
};

int32_t main()
{
    int n, k;
    cin>>n>>k;
    int arr[n];
    for(int i=0; i<n; i++) cin>>arr[i];
    Solution ans;
    cout<<ans.findPages(arr, n, k);
    return 0;
}
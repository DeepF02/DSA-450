// Find the triplet that sum to a given value
#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
    //Function to find if there exists a triplet in the 
    //array A[] which sums up to X.
    bool find3Numbers(int arr[], int n, int X)
    {
        //Your Code Here
        if(n<2)return 0;
        sort(arr, arr+n);
        int sum=0, j=n-1, i=0;
        for(int it=0; it<n; it++){
            i=it+1;
            j=n-1;
            while(i<j){
                sum=arr[it]+arr[i]+arr[j];
                if(X==sum)return 1;
                else if(sum>X)j--;
                else i++;
            }
        }
    return 0;
    }
    
};

int32_t main()
{
    int n, x;
    cin>>n>>x;
    int arr[n];
    for(int i=0; i<n; i++)cin>>arr[i];
    Solution ans;
    cout<<ans.find3Numbers(arr, n, x);
    return 0;
}

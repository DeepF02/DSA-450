// Trapping Rain water problem
#include <bits/stdc++.h>
using namespace std;

class Solution{

    // Function to find the trapped water between the blocks.
    public:
    long long trappingWater(int arr[], int n){
        // maxL[i] & maxR[i] contains height of tallest bar to the  left & right of bar at ith index including itself.
        int maxL[n], maxR[n];
        maxL[0]=arr[0];
        maxR[n-1]=arr[n-1];
        long long sum=0;
        for(int i=1; i<n; i++)maxL[i]=max(maxL[i-1], arr[i]);
        for(int i=n-2; i>=0; i--)maxR[i]=max(maxR[i+1], arr[i]);
        // Storing the result by choosing the minimum of heights of tallest bar to
        // the right and left of the bar at current index and also subtracting the
        // value of current index to get water accumulated at current index.
        for(int i=0; i<n; i++)sum=sum+min(maxL[i], maxR[i])-arr[i];
        return sum;
    }
};

int32_t main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++) cin>>arr[i];
    Solution ans;
    cout<<ans.trappingWater(arr, n);
    return 0;
}
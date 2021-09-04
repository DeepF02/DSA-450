//Find minimum no. of jumps to reach end of array
#include <bits/stdc++.h>
using namespace std;

void inputArray(int arr[], int n){
    for(int i=0; i<n; i++)
    cin>>arr[i];
}
int minJumps(int arr[], int n)
{
    // The number of jumps needed to reach the starting index is 0
    if (n <= 1)
        return 0;
    // Return -1 if not possible to jump
    if (arr[0] == 0)
        return -1;
    // initialization stores all time the maximal reachable index in the array.
    int maxReach = arr[0];
    // stores the number of steps
    // we can still take
    int step = arr[0];
    // stores the number of jumps necessary to reach that maximal reachable position.
    int jump = 1;
    // Start traversing array
    for (int i = 1; i < n; i++) {
        // Check if we have reached the end of the array
        if (i == n - 1)
            return jump;
        // updating maxReach
        maxReach = max(maxReach, i + arr[i]);

        // we use a step to get to the current index
        step--;

        // If no further steps left
        if (step == 0) {
            // we must have used a jump
            jump++;
            // Check if the current index/position or lesser index is the maximum reach point from the previous indexes
            if (i >= maxReach)
                return -1;
            // re-initialize the steps to the amount of steps to reach maxReach from position i.
            step = maxReach - i;
        }
    }
    return -1;
}
int32_t main()
{
    /*int t;
    cin>>t;
    while(t--){}*/
    int n, k;// c=0, mx=INT_MIN;
    cin>>n;
    int arr[n]; 
    inputArray(arr, n);
    k=minJumps(arr, n);
    cout<<k<<endl;
    return 0;
}
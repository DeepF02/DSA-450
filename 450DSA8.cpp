//Using Kadane's Algorithm to get sum of contigous subarray s
#include <bits/stdc++.h>
using namespace std;

int32_t main(){
    int n;
    cout<<"Enter size of array : ";
    cin>>n;

    int a[n];
    cout<<"Enter elements of array : ";
    for(int i=0; i<n; i++){
        cin>>a[i];
    }
    int maxSum=INT_MIN;
    int currsum=0;
    for(int i=0; i<n; i++){
        currsum+=a[i];
        if(currsum<0){
            currsum=0;
        }
        maxSum=max(maxSum,currsum);
    }
    if(maxSum==0){
        maxSum=a[0];
        for(int i=0; i<n; i++){
            currsum=a[i];
            maxSum=max(currsum,maxSum);
        }
    }
    cout<<maxSum<<endl;
    return 0;
}
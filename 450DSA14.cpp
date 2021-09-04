//Kadane's Algorithm 
#include <bits/stdc++.h>
using namespace std;

int32_t main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0; i<n; i++) cin>>a[i];
    
    int maxSum=INT_MIN, currsum=0;
    for(int i=0; i<n; i++){
        currsum+=a[i];
        if(currsum<0) currsum=0;
        
        maxSum = max(maxSum,currsum);
    }
    // if all the elements of an array are negative
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
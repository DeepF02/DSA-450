//Find minimize diff betn high & low of array
#include <bits/stdc++.h>
using namespace std;

void inputArray(int arr[], int n){
    for(int i=0; i<n; i++)
    cin>>arr[i];
}

int32_t main()
{
    int n, k, maxElement, minElement, result=INT_MAX, ans;
    cin>>k>>n;
    int arr[n];
    inputArray(arr, n);
    sort(arr, arr+n);
    for(int i=1; i<n; i++){//each iteration will be for diff possible arrays combination
        if(arr[i]>=k){
            maxElement=max(arr[i-1]+k, arr[n-1]-k);//this will give max element of this itr. arr
            minElement=min(arr[0]+k, arr[i]-k);//this will give min element of this itr. arr
            ans=maxElement-minElement;//this will give min diff of towers for this itr. array
            result=min(ans, result);
        }
    }
    cout<<result<<endl;
    return 0;
}
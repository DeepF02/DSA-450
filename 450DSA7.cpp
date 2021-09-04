// C++ program for the union of two arrays using Set
#include <bits/stdc++.h>
using namespace std;

void inputArr(int arr[], int n)
{
    for(int i=0; i<n; i++)
    cin>>arr[i];
}
void outputArray(int arr[], int n){
    for(int i=0; i<n; i++)
    cout<<arr[i]<<" ";

    return;
}
void cyclicRotation(int a[], int n)
{
    for(int i=(n-1); i>0; i--){
        int temp = a[i];
        a[i]=a[i-1];
        a[i-1]=temp;
    }
    return;
}
 
// Driver Code
int32_t main()
{   
    int n;
    cin>>n;
    int a[n];
    inputArr(a,n);
    cyclicRotation(a, n);
    outputArray(a, n);
    return 0;
}
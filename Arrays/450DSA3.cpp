#include<bits/stdc++.h>
using namespace std;

void swap(int arr[], int i, int j)
{
    int temp= arr[i];
    arr[i]=arr[j];
    arr[j]=temp;
}

int partition(int arr[], int l, int r)
{
    //l is starting index of arr and r is ending index of arr
    int pivot = arr[r];//pivot can be any element of array
    int i= l-1;

    for(int j=l; j<r; j++){
        if(arr[j] < pivot){
            i++;
            swap(arr, i, j);
        }
    }
    swap(arr, i + 1, r);//to swap pivot & smallest element
    return (i + 1);//return index of smallest element
}

void quickSort(int arr[], int l, int r)
{
    if(l < r){

        int pi=partition(arr, l, r);//index of pivot
        quickSort(arr, l, pi - 1);//sorting arr till pivot-1
        quickSort(arr, pi + 1, r);//sorting arr after pi+1

    }
}
int32_t main()
{
    //kth smallest element
    //using quicksort algorithm
    int n;
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    quickSort(arr, 0, n-1);
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    } 
    cout<<endl;
    int k;
    cin>>k;
    cout<<arr[k-1]<<endl;
    return 0;
}
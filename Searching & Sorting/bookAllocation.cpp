// Allocate minimum number of books/pages to students (best binary search problem)
#include <bits/stdc++.h>
using namespace std;

class Solution 
{
    public:
    //Function to find minimum number of pages.
    bool isValid(int arr[], int n, int k, int mid){ //IMP For all similar binary search problems
        int students=1, sum=0;
        for(int i=0; i<n; i++){
            sum+=arr[i];
            if(sum>mid){
                sum=arr[i];
                students++;
            }
            if(students>k)return false;
        }
        return true;
    }
    int findPages(int arr[], int n, int k) 
    {
        //code here
        int start=0, end=0, result=-1;
        if(n<k)return -1;
        for(int i=0; i<n; i++){
            start=max(start, arr[i]);
            end+=arr[i];
        }
        while(start<=end){
            int mid= start + (end - start)/2; //prevents integer overflow;
            if (isValid(arr, n, k, mid)){
                result=mid;
                end = mid-1;
            }
            else start=mid+1;
        }
        return result;
    }
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
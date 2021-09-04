//Merge 2 sorted arrays without using Extra space.
#include <bits/stdc++.h>
#define ll long long int
using namespace std;

class Solution{
public:
	void merge(int arr1[], int arr2[], int n, int m) {
	    // code here
	    int i=0, j=0;
	    vector<int>arr3;
	    while(i<n && j<m){
	       if(arr1[i]>arr2[j]){
	           arr3.push_back(arr2[j]);
	           j++;
	       }
	       else{
	           arr3.push_back(arr1[i]);
	           i++;
	       }
	    }
	   while(i<n){
	       arr3.push_back(arr1[i]);
	       i++;
	   }
	   while(j<m){
	        arr3.push_back(arr2[j]);
	        j++;
	   }
	   for(int x=0; x<n; x++){
	       arr1[x]=arr3[x];
	   }
	   for(int x=0; x<m; x++){
	       arr2[x]=arr3[x+n];
	   }
	}
};

void inputArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
}
void outputArray(int arr[], int n){
    for(auto i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
}

int32_t main()
{
    int n, m;
    cin >> n>> m;
    int arr1[n], arr2[m];
    inputArray(arr1, n);
    inputArray(arr2, m);
    Solution solve;
    solve.merge(arr1, arr2, n, m);
    outputArray(arr1, n);
    outputArray(arr2, m);

    return 0;
}
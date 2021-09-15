#include<bits/stdc++.h>
using namespace std;

int32_t main()
{
    //reservsing an array
    int arr[] = {1, 2, 3, 4, 5, 6};
    int n = sizeof(arr)/sizeof(arr[0]);
    int Maximum=arr[0];
    int Minimum=arr[0];
    for(int i=0; i<n; i++){
        Maximum=max(Maximum,arr[i]);
        Minimum=min(Minimum,arr[i]);
    }
    cout<<"Maximum is "<<Maximum<<endl;
    cout<<"Miniimum is "<<Minimum<<endl;
    
    return 0;
}
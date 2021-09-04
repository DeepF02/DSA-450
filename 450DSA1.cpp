#include<bits/stdc++.h>
using namespace std;

int32_t main()
{
    //reserveing an array
    int n;
    cin>>n;
    int a[n];
    for(int i=0; i<n; i++){
        cin>>a[i];
    }
    for(int i=n-1; i>=0; i--){
        cout<<a[i]<<" ";
    }
    cout<<endl;

    //reserving a string
    string s="deep";
    reverse(s.begin(), s.end());
    cout<<s<<endl;
    return 0;
}
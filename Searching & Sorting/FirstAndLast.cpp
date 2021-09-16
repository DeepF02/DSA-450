#include<bits/stdc++.h>
using namespace std;

vector<int> find(int arr[], int n , int x )
{
    vector<int>ans;
    int j=n-1;
    bool flag=0;
    for(int i=0; i<n; ++i){
        if(arr[i]==x){
            ans.push_back(i);
            flag=1;
            break;
        }
        
    }
    if(flag==0){
        ans.push_back(-1);
        ans.push_back(-1);
        return ans;
    }
    for(int i=n-1; i>=0; --i){
        if(arr[i]==x){
            ans.push_back(i);
            break;
        }
    }
    return ans;
}
int32_t main()
{
    int n, x;
    cin>>n>>x;
    int arr[n];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    vector<int>ans=find(arr, n, x);
    for(int i=0; i<2; i++)cout<<ans[i]<<" ";
    return 0;
}
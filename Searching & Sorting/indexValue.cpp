#include<bits/stdc++.h>
using namespace std;

class Solution{
public:

	vector<int> valueEqualToIndex(int arr[], int n) {
	    vector<int>ans;
	    for(int i=0; i<n; i++){
	        if(arr[i]==i+1)ans.push_back(arr[i]);
	    }
	    return ans;
	}
};
int32_t main(){
	int n;
	cin>>n;
	int arr[n];
	for(int i=0; i<n ; ++i)cin>>arr[i];
	Solution ans;
	auto out=ans.valueEqualToIndex(arr, n);
	if(out.empty())cout<<"Not Found";
	else for(auto x:out)cout<<x<<" ";
	return 0;
}
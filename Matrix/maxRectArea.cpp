// Maximum size rectangle
#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define MAX 50

class Solution{
  public:
    
    vector<int>previousSmaller(int store[], int m){
        stack<int>s;
        vector<int>prevSmall(m);
        for(int i=0; i<m; i++){
            while(!s.empty() && store[s.top()]>=store[i]) s.pop();
            if(s.empty()) prevSmall[i]=-1;
            else prevSmall[i] = s.top();
            s.push(i);
        }
        return prevSmall;
    }
    vector<int>nextSmaller(int store[], int m){
        stack<int>s;
        vector<int>nextSmall(m);
        for(int i=m-1; i>=0; i--){
            while(!s.empty() && store[s.top()]>=store[i]) s.pop();
            if(s.empty()) nextSmall[i]=m;
            else nextSmall[i] = s.top();
            s.push(i);
        }
        return nextSmall;
    }
    int maxHistogram(int arr[], int n){
        int maxArea=0;
        vector<int>prevSmall=previousSmaller(arr, n);
        vector<int>nextSmall=nextSmaller(arr, n);
        for(int i=0; i<n; i++){
            int temp = (nextSmall[i]-prevSmall[i]-1)*arr[i];
            maxArea=max(maxArea, temp);
        }
        return maxArea;
    }
    int maxArea(int M[MAX][MAX], int n, int m) {
        // Your code here
        int ans=0;
        int currArr[m]={0};
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                (M[i][j]==0)?currArr[j]=0:currArr[j]+=M[i][j];
            }
            int temp = maxHistogram(currArr, m);
            ans=max(ans, temp);
        }
        return ans;
    }
};

int32_t main()
{
    Solution ans;
    int n, m;
    cin>>n>>m;
    int arr[MAX][MAX];
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++) cin>>arr[i][j];
    }
    ll area = ans.maxArea(arr, n, m);
    cout<<area<<endl;
    return 0;
}
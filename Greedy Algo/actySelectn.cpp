// Activity Selection Problem
#include <bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    //Function to find the maximum number of activities that can be performed by a single person
    int maxMeetings(int start[], int end[], int n)
    {
        int cnt=1;
        vector< pair <int,int> > vect; 
        for(int i=0; i<n; i++) vect.push_back(make_pair(end[i], start[i]));
        sort(vect.begin(), vect.end());//Sort's wrt to first. 
        int j=1, i=0;
        while(i<n && j<n){
            if(vect[j].second>vect[i].first){
                cnt++;
                i=j;
            }
            j++;
        }
        return cnt;
    }
};

int32_t main()
{
    int n;
    cin>>n;
    int start[n], end[n];
    for(int i=0; i<n; i++) cin>>start[i];
    for(int i=0; i<n; i++) cin>>end[i];
    Solution ans;
    cout<<ans.maxMeetings(start, end, n);
    return 0;
}
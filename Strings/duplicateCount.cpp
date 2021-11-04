//Find Duplicate characters in a string
#include <bits/stdc++.h>
using namespace std;

void duplicateCount(string s){
    map<char, int>countDup;
    for(int i=0; i<s.size(); i++) countDup[s[i]]++;
    for(auto it: countDup) if(it.second>1)cout<<it.first<<": count= "<<it.second<<endl;
}

int32_t main()
{
    string s;
    cin>>s;
    duplicateCount(s);
    return 0;
}
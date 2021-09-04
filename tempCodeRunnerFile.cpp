Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals){
        int n=intervals.size(), i;
        vector<vector<int>>::iterator it1, it2;
        vector<vector<int>>ans;
        it1=intervals.begin();
        it2=intervals.end();
        vector<int>x, y;
        if(n<2) return intervals;
        sort(it1, it2);
        for(i=1; i<n; ++i){
            x=intervals[i-1];
            y=intervals[i];
            if(x[1]>=y[0]) (x[1]<=y[1])?intervals[i]={x[0], y[1]}:intervals[i] = {x[0], x[1]};
                
            else ans.push_back(intervals[i-1]);
        }
        ans.push_back(intervals[i-1]);
        return ans;
    }
};
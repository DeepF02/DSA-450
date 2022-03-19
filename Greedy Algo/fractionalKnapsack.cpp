// Fractional Knapsack Problem
#include <bits/stdc++.h>
using namespace std;

struct Item{
    int value;
    int weight;
};

//double is a cpp Datatype that can store int value upto 8 decimal points
class Solution
{
    public:
    //Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        // Your code here
        /* The basic idea of the greedy approach is to calculate the ratio value/weight for each item 
        and sort the item on basis of this ratio. Then take the item with the highest ratio and add 
        them until we can’t add the next item as a whole and at the end add the next item's fraction till knapsack is full*/
        vector<pair<double, double>>v(n);// we will store ration here
        for(auto i=0; i<n; ++i){// we store ratio of vale/weight
            v[i]= {(double)arr[i].value/(double)arr[i].weight, (double)arr[i].weight};
        }
        double ans=0.0;
        sort(v.rbegin(), v.rend());// we sort v by second element i.e weight
        for(auto i:v){
            // If we can't add current Item, add fractional part of it
            if(W<i.second){
                ans+=W*i.first;
                break; // as knapsack has reached its capacity
            }
            // If adding Item won't overflow, add it completely
            else{
                ans+=i.first*i.second;
                W-=i.second;
                if(W==0)break; // as knapsack has reached its capacity
            }
        }
        return ans;
    }
};

int32_t main()
{
    Solution greedy;
    int W = 50; //    Weight of knapsack
    Item arr[] = { { 60, 10 }, { 100, 20 }, { 120, 30 } };
    int n = sizeof(arr) / sizeof(arr[0]);
    // Function call
    cout << "Maximum value we can obtain = "<< greedy.fractionalKnapsack(W, arr, n);
   
   return 0;
}
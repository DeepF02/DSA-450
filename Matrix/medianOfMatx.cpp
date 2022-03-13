// Find median in a row wise sorted matrix
#include <bits/stdc++.h>
using namespace std;
#define ll long long int

class Solution
{
private:
    int cntSmallerThanMed(vector<int> &row, int median)
    {
        int lo = 0, hi = row.size() - 1;
        while (lo <= hi)
        {
            int mid = (lo + hi) >> 1; // same as (lo+hi)/2
            (row[mid] <= median) ? lo = mid + 1 : hi = mid - 1;
        }
        return lo;
    }

public:
    // Funtion to return median of a row wise sorted matrix
    int median(vector<vector<int>> &matx, int r, int c)
    {
        int mn = INT_MAX, mx = INT_MIN;
        // Below for loop can be avoid if we define mn eleemnt as 1 & mx element as 10^9 i.e max constraint of matx element
        for (int i = 0; i < r; ++i)
        {
            mn = min(matx[i][0], mn);
            mx = max(matx[i][c - 1], mx);
        }
        // We do binary search to get just greater then element of our mn element i.e median
        while (mn <= mx)
        {
            int med = mn + (mx - mn) / 2, cnt = 0; // we can also do {(mn+mx)>>1} instead
            // // Upper_bound is a STL fn that Returns an iterator pointing to the first element in the range [first,last) which compares greater than val i.e med.
            // for (int i = 0; i < r; ++i) // cnt stores no. of elements lower then med in each row
            //     cnt += upper_bound(matx[i].begin(), matx[i].end(), med) - matx[i].begin();

            // In Interview we can't use Stl very oten so we right our own function to get cnt of just lower then med element in row
            for (int i = 0; i < r; ++i)
                cnt += cntSmallerThanMed(matx[i], med);

            // If cnt is lower then equal to total no. of elements that means we need to increase our min or else we lower our max
            (cnt <= (r * c) / 2) ? mn = med + 1 : mx = med - 1;
        }

        return mn;
    }
};

int32_t main()
{
    Solution matx;
    vector<vector<int>> arr(3, vector<int>(3));
    arr[0][0] = 1;
    arr[0][1] = 3;
    arr[0][2] = 5;
    arr[1][0] = 2;
    arr[1][1] = 6;
    arr[1][2] = 9;
    arr[2][0] = 3;
    arr[2][1] = 6;
    arr[2][2] = 0;
    cout << "Median of following Matyrix is : " << matx.median(arr, 3, 3) << endl;
    return 0;
}
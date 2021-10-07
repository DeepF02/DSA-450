//EKOSPOJ: Problem of spof uses same logic as Book Allocation
#include <bits/stdc++.h>
using namespace std;

bool isValid(int arr[], int n, int k, int mid)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > mid) sum += arr[i]-mid;
        if (sum >= k) return true;
    }
    return false;
}

int minHeight(int arr[], int n, int k)
{
    int start = arr[0], end = 0, result = -1;
    for (int i = 0; i < n; i++)
    {
        start = min(start, arr[i]);
        end = max(end, arr[i]);
    }
    while (start <= end)
    {
        int mid = start + (end - start) / 2; //prevents integer overflow;
        if (isValid(arr, n, k, mid))
        {
            result = mid;
            start = mid + 1;
        }
        else
            end = mid - 1;
    }
    return result;
}

int32_t main()
{
    int n, k;
    cin >> n >> k;
    int arr[n];
    for (int i = 0; i < n; i++) cin >> arr[i];
    cout << minHeight(arr, n, k);
    return 0;
}
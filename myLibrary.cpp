//All c++ functions library
#include <bits/stdc++.h>
using namespace std;

#define ll long long int

//fast scan & print
void start()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}
int binarySearch(int arr[], int N, int K)
{
    int l = 0, r = N, ans, prevM, m;

    while (l < r)
    {
        m = (l + r) / 2;
        if (K == arr[m])
            return 1;
        else if (K > arr[m])
        {
            l = m;
            prevM = m;
            if (prevM == m)
                break;
        }
        else
        {
            r = m;
            prevM = m;
            if (prevM == m)
                break;
        }
    }
    return -1;
}

//To covert binary to decimal
int binaryToDecimal(int n)
{
    int ans = 0, x = 1;
    while (n > 0)
    {
        int y = n % 10;
        ans += x * y;
        x *= 2;
        n = n / 10;
    }
    return ans;
}
//To covert decimal to binary
int decimalToBinary(int n)
{
    int x = 1, ans = 0;
    //to get max power of 2
    while (x < n)
    {
        x *= 2;
    }
    while (x > 0)
    {
        int lastdigit = n / x;
        n -= lastdigit * x;         //to get reaminder of n/x after 1st division
        ans = ans * 10 + lastdigit; //appending 0/1 at last of our ans
        x /= 2;                     //decrement x by pwer of 2
    }
    return ans;
}
//cyclic shift left
string cyclicShift(string s, int n)
{
    char temp;
    for (int i = 0; i < (n - 1); i++)
    {
        temp = s[i];
        s[i] = s[++i];
        s[++i] = temp;
    }
    return s;
}
//To get length of a int (if possible convert int to string and use lentgh() func.)
int lengthOfInt(int x)
{
    int z = 0;
    while (x)
    {
        x /= 10;
        z++;
    }
    return z;
}
//Input for matrix
int matrixInput(int arr[n][], int n, int m)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
        }
    }
    return arr[n][m];
}
void inputArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        cin >> arr[i];
}
void inputVector(vector<ll> v, ll n)
{
    ll temp;
    for (ll i = 0; i < n; i++)
    {
        cin >> temp;
        v.push_back(temp);
    }
}
//All c++ std template
#include <bits/stdc++.h>
using namespace std;

int32_t main()
{

    return 0;
}

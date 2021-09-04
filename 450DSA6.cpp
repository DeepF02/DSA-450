// C++ program for the union and intersection of two arrays using Set
#include <bits/stdc++.h>
using namespace std;

void inputArr(int arr[], int n)
{
    for(int i=0; i<n; i++)
    cin>>arr[i];
}
void outputArr(int arr[], int n){
    for(int i=0; i<n; i++)
    cout<<arr[i];
}
void getUnion(int a[], int n, int b[], int m)
{
     
    // Defining set container s
    set<int> s;
   
    // Inserting array elements in s
    for (int i = 0; i < n; i++)
      s.insert(a[i]);
   
    for (int i = 0; i < m; i++)
        s.insert(b[i]);
    cout << "Number of elements after union operation: " << s.size() << endl;
      cout << "The union set of both arrays is :" << endl;
    for (auto itr = s.begin(); itr != s.end(); itr++)
        cout << *itr<< " "; // s will contain only distinct elements from array a and b
    cout<<endl;
}
// Prints intersection of 2 arrays
void printIntersection(int arr1[], int arr2[], int n1, int n2)
{
    set<int> hs;
 
    // Insert the elements of arr1[] to set S
    for (int i = 0; i < n1; i++)
        hs.insert(arr1[i]);
    cout << "The intersection set of both arrays is :" << endl;
    for (int i = 0; i < n2; i++){
        // If element is present in set then push it to vector v
        if (hs.find(arr2[i]) != hs.end())//iteration i in arr2 to fnd it and compare it with existing elements of set hs
            cout <<arr2[i]<<" ";
    }
}
  
// Driver Code
int main()
{   
    int n,m;
    cin>>n>>m;
    int a[n];
    inputArr(a,n);
    int b[m];
    inputArr(b,m);
    getUnion(a, n, b, m);
    printIntersection(a,b,n,m);
}
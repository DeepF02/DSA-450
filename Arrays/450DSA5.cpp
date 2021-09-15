//Move all the negative elements to one side of the array 
#include <iostream>
using namespace std;

void swap(int arr[],int i,int j)
{
    int temp;
    temp =arr[i];
    arr[i]=arr[j];
    arr[j]=temp;
    return;
}

int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    int k=0;
    for(int i=0; i<n; i++){
        if(arr[i]<0){
            swap(arr,i,k);
            k++;
        }
    }
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    
	
	return 0;
}
// Design a Stack that supports getMin() in O(1) time and O(1) extra space.
#include <bits/stdc++.h>
using namespace std;
stack<int>s;
int minValue=0; //This will be our global var that will store minValue of stack

// A user defined stack that supports getMin() in addition to push() and pop()
void push(stack<int>& s, int a){
	if(s.size()==0){
	    minValue=a;
	    s.push(a);
	}
    // If new number is less than minValue we store currValue in minvalue 
    // And we store top of the stack with  formula (2*currValue-minValue) this way top of th stack ele will work as flag for us 
	else if(a<=minValue){
	    s.push(2*a-minValue);
	    minValue=a;
	}
	else s.push(a);
}

bool isFull(stack<int>& s,int n){
	return (s.size()==n)?true:false;
}

bool isEmpty(stack<int>& s){
	return (s.size()==0)?true:false;
}

int pop(stack<int>& s){
    if(isEmpty(s))return -1;
    // Minimum will change as the minimum element of the stack is being removed.
    else if(s.top()<=minValue){//Checking the flag
        int temp=minValue;
        minValue=2*temp-s.top(); // We store prevoius value of minimum using same formula (2*currValue-minValue)
        s.pop();
        return temp;
    }
    int top=s.top();
    s.pop();
    return top;
}

int getMin(stack<int>& s){
    return (isEmpty(s))?-1:minValue;
}

int32_t main()
{
    int n, a;
    cin>>n;
    while(!isEmpty(s))s.pop();
    while(!isFull(s,n)){
        cin>>a;
        push(s,a);
    }
    cout<<getMin(s);
    return 0;
}

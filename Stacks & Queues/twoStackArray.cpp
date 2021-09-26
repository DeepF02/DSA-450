//All c++ std template
#include <bits/stdc++.h>
using namespace std;

class twoStacks {
    int* arr;
    int size, top1, top2;
public:
    // Constructor
    twoStacks(int n)
    {
        size = n;
        arr = new int[n];
        top1 = n / 2 + 1;
        top2 = n / 2;
    }
    // Method to push an element x to stack1
    void push1(int x)
    {
        if(top1==top2)return;
        arr[++top1]=x;
    }
    // Method to push an element x to stack2
    void push2(int x)
    {
        // There is at least one empty space for new element
        if(top1==top2)return;
        arr[--top2]=x;
    }
    // Method to pop an element from first stack
    int pop1()
    {
        if(top1==-1)return -1;
        return arr[top1--];
    }
    // Method to pop an element from second stack
    int pop2()
    {
        if(top2==size)return -1;
        return arr[top2++];
    }
};

int32_t main()
{
    twoStacks ts(5);
    ts.push1(5);
    ts.push2(10);
    ts.push2(15);
    ts.push1(11);
    ts.push2(7);
    cout << "Popped element from stack1 is "<< " : " << ts.pop1()<< endl;
    ts.push2(40);
    cout << "\nPopped element from stack2 is "<< ": " << ts.pop2()<< endl;
    return 0;
}

//Impplementing Stack using Vector in c++
#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back
#define po pop_back()

class Stack
{
private:
    int size;
    vector<int> arr;
    int top;
    int bound;

public:
    // structure of stack
    Stack(int n)
    {
        size = n;
        top = -1;
        bound = 2 * size;
        arr.reserve(bound);
    }
    /* Function to push an element to the stack */
    void push(int data)
    {
        if (full()) throw new exception();
        arr[++top] = data;
    }
    /* Function to pop an element from the stack */
    void pop()
    {
        if (empty()) throw new exception();
        arr.po;
        top--;
    }
    /* Function to return top element of the stack */
    int peak()
    {
        if (top == -1) throw new exception();
        return arr[top];
    }
    /* Function to check whether stack is empty */
    bool empty()
    {
        return (top == -1)? true:false;
    }
    /* Function to check whether stack is full */
    bool full()
    {
        return (top ==size -1)? true:false;
    }
};

int32_t main()
{
    Stack s(10);
    s.push(5);
    s.push(4);
    s.push(3);
    s.push(2);
    s.push(1);
    s.push(0);
    s.pop();
    s.pop();
    cout<<s.peak()<<endl;

    return 0;
}

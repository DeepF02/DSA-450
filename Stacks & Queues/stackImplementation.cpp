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
    // Constructor
    Stack(int n)
    {
        this->size = n;
        this->top = -1;
        this->bound = 2 * size;
        this->arr.reserve(this->bound);
    }
    void push(int data)
    {
        if (this->full())
            throw new exception();
        arr[++this->top] = data;
    }
    void pop()
    {
        if (this->empty())
            throw new exception();
        arr.po;
        top--;
    }
    int peak()
    {
        if (this->top == -1)
            throw new exception();
        return arr[this->top];
    }
    bool empty()
    {
        if (this->top == -1)
            return true;
        return false;
    }
    bool full()
    {
        if (this->top == this->size - 1)
            return true;
        return false;
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
    cout<<s.peak()<<endl;

    return 0;
}

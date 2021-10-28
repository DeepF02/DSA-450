// Implement Queue using Stack
#include <bits/stdc++.h>
using namespace std;

class StackQueue
{
    stack<int> s1, s2;

 public:
    void push(int x)
    {
        s1.push(x);
    }
    int pop()
    {
        if (s2.empty())
        {
            while (!(s1.empty()))
            {
                s2.push(s1.top());
                s1.pop();
            }
        }
        if (s2.empty())
            return -1;
        int result = s2.top();
        s2.pop();
        return result;
    }
};

int32_t main()
{
    StackQueue q;
    q.push(1);
    q.push(2);
    q.push(3);

    cout << q.pop() << '\n';
    cout << q.pop() << '\n';
    cout << q.pop() << '\n';

    return 0;
}
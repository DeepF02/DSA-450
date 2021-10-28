// Implement Stack using Queue
#include <bits/stdc++.h>
using namespace std;

class QueueStack
{
    queue<int> q1, q2;
public:
    void push(int x)
    {
        q1.push(x);
    }
    int pop()
    {
        if (q2.empty() && q1.empty())
            return -1;
        int result = q1.back();
        if (q2.empty())
        {
            while ((q1.size() > 1))
            {
                q2.push(q1.front());
                q1.pop();
            }
            q1.pop();
        }
        swap(q1, q2);
        return result;
    }
};

int32_t main()
{
    QueueStack s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);

    cout << s.pop() << endl;
    cout << s.pop() << endl;
    cout << s.pop() << endl;
    cout << s.pop() << endl;
    // cout << s.pop() << endl;

    return 0;
}
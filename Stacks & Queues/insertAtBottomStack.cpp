//Reverse a stack using recursion
#include <bits/stdc++.h>
using namespace std;

stack<int>s; //defining stack globally

// Below is a recursive function that inserts an element at the bottom of a stack.
void insert_at_bottom(int x)
{
    if(s.empty())s.push(x);
    else{
        // All items are held in Function Call Stack until we reach end of the stack When the stack becomes empty,
        // the st.size() becomes 0, the above if part is executed and the item is inserted at the bottom
             
        int a = s.top();
        s.pop();
        insert_at_bottom(x);
        // push allthe items held in Function Call Stack once the item is inserted at the bottom
        s.push(a);
    }
}
int32_t main()
{
    insert_at_bottom(1);
    insert_at_bottom(2);
    insert_at_bottom(3);
    insert_at_bottom(4);
    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }
    cout<<endl;

    return 0;
}
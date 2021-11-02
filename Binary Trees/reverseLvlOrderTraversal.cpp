// Reverse level order traversal of BT
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};
class Solution
{
public:
    //Function to return the level order traversal of a tree.
    vector<int> levelOrder(Node *root)
    {
        queue<Node *> q;
        stack<int> s;
        vector<int> ans;
        if (root)
            q.push(root);
        while (!q.empty())
        {
            /* Dequeue node and make it root */
            root = q.front();
            q.pop();
            s.push(root->data);
            /* Enqueue right child */
            if (root->right)
                q.push(root->right); // NOTE: RIGHT CHILD IS ENQUEUED BEFORE LEFT
            /* Enqueue left child */
            if (root->left)
                q.push(root->left);
        }
        // Now pop all items from stack one by one and print them
        while (!s.empty())
        {
            ans.push_back(s.top());
            s.pop();
        }
        return ans;
    }
    //Time Complexity O(N)
    //Space Complexity O(N)
};

int32_t main()
{
    /* Constructed binary tree is
              10
            /   \
          20     30
         /  \   /
       40   50 60
      /  \
     70  80
    */
    Node *root = new Node(10);
    root->left = new Node(20);
    root->right = new Node(30);
    root->left->left = new Node(40);
    root->left->left->left = new Node(70);
    root->left->right = new Node(50);
    root->right->left = new Node(60);
    root->left->left->right = new Node(80);

    Solution tree;
    vector<int> ans = tree.levelOrder(root);
    for (auto x : ans)
        cout << x << " ";
    cout << endl;

    return 0;
}
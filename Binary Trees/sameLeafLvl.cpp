// Check if all leaf nodes are at same level or not
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
    // Recursive function which checks whether all leaves are at same level 
    bool checkUtil(struct Node *root, int level, int *leafLevel)
    {
        // Base case
        if (!root)return true;
        // If a leaf node is encountered
        if (!root->left && !root->right){
            // When a leaf node is found first time
            if (*leafLevel == 0)
            {
                *leafLevel = level; // Set first found leaf's level
                return true;
            }
            // If this is not first leaf node, compare its level with first leaf's level
            return (level == *leafLevel);
        }
        // If this node is not leaf, recursively check left and right subtrees
        return checkUtil(root->left, level + 1, leafLevel) && checkUtil(root->right, level + 1, leafLevel);
    }
    // The main function to check if all leafs are at same level. It mainly uses checkUtil()
    bool check(struct Node *root)
    {
        int level = 0, leafLevel = 0;
        return checkUtil(root, level, &leafLevel);
    }

    //Function to return true if all leaf nodes are at same level, else false **Iterative**
    // bool check(Node *root)
    // {
    //     //Your code here
    //     queue<pair<Node *, int>> q; // q={currNode, height};
    //     //creating a map to store nodes at a particular lvl.
    //     map<int, int> mp;
    //     if (root)
    //         q.push({root, 0});
    //     // We traverse the tree in level order traversal
    //     while (!q.empty())
    //     {
    //         auto ptr = q.front();
    //         q.pop();
    //         int lvl = ptr.second; // this stores level
    //         Node *curr = ptr.first;
    //         if (!curr->left && !curr->right)
    //             mp[lvl] = curr->data; //if the curr node is left node we push it tp map atthe key:level
    //         if (curr->left)
    //             q.push({curr->left, lvl + 1});
    //         if (curr->right)
    //             q.push({curr->right, lvl + 1});
    //     }
    //     return (mp.size() == 1) ? 1 : 0; //if map is of 1 suze i.e. all leafs are at same level
    // }
    //Time Complexity O(N)
    //Space Complexity O(N + Height)
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
    Node* root = new Node(10);
    root->left = new Node(20);
    root->right = new Node(30);
    root->left->left = new Node(40);
    root->left->left->left = new Node(70);
    root->left->right = new Node(50);
    root->right->left = new Node(60);
    root->left->left->right = new Node(80);

    /* Constructed binary tree is
              1
            /  \
          2     3
         /    /  \
       4     5   6
    
    */
    // Node *root = new Node(1);
    // root->left = new Node(2);
    // root->right = new Node(3);
    // root->left->right = new Node(4);
    // root->right->left = new Node(5);
    // root->right->right = new Node(6);

    Solution tree;
    (tree.check(root)) ? cout << "All leaf nodes are at same level\n" : cout << "All leaf nodes are NOT at same level\n";

    return 0;
}
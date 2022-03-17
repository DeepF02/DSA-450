// Deletion of a node in a BST
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int val;
    Node *left;
    Node *right;
    Node(int data)
    {
        val = data;
        left = right = NULL;
    }
};
class Solution
{

public:
    // Function to find the minimum element in the given BST.
    int minValue(Node *root)
    {
        if (!root) return -1;
        if (!root->left) return root->val;
        minValue(root->left);
        // return 0;
    } 

    // Function to find the maximum element in the given BST.
    int maxValue(Node *root)
    {
        if (!root) return -1;
        if (!root->right) return root->val;
        maxValue(root->right);
        // return 0;
    }
    // Time Complexity: The worst-case time complexity of search and insert operations is O(h) && Space is constant
};

int32_t main()
{
    /* Constructed Binary Search Tree is
              20
            /   \
          10     30
         /  \   /
        4   12 25
      /  \
     3   5
    */
    Node *root = new Node(20);
    root->left = new Node(10);
    root->right = new Node(30);
    root->left->left = new Node(4);
    root->left->left->left = new Node(3);
    root->left->right = new Node(12);
    root->right->left = new Node(25);
    root->left->left->right = new Node(5);

    Solution BST;
    cout <<"Maximum node value in BST is "<<BST.maxValue(root)<<endl;
    cout <<"Minimum node value in BST is "<<BST.minValue(root)<<endl;

    return 0;
}
// Check if a tree is a BST or not
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
    // traverse the tree in inorder fashion and keep track of prev node this way we don't need a array
    // **{Note: Inorder Travsel of BST is always in soted order}**
    int prev=INT_MIN;
    ///Function to check whether a Binary Tree is BST or not.
    bool isBST(Node* root)  //Method 1 Inorder traversal method
    {
        // Your code here
        if(!root)return 1; /* an empty tree is BST */
        if(!isBST(root->left)) return 0;
        if(prev>=root->data)return 0; // Allows only distinct valued i.e greater then prev nodes 
        prev=root->data;
        return isBST(root->right);
        // return bstRange(root, INT_MIN, INT_MAX); //Method 2 Upperbound lowerBound range method
    } // Time Complexity: O(N) && Space is constant
    
    // Returns true if the given tree is a BST and its values are >= min and <= max. */
    bool bstRange(Node *root, int min, int max){
        if(!root)return 1; /* an empty tree is BST */
        if(root->data<min || root->data>max) return 0;// false if this node violates the min/max constraint
        // otherwise check the subtrees recursively, tightening the min or max constraint
        return bstRange(root->left, min, root->data-1) && bstRange(root->right, root->data+1, max);
    }
    
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
    (BST.isBST(root))?cout<<"Given Binary Tree Is a BST"<<endl:cout<<"Given Binary Tree is Not a BST\n";

    return 0;
}
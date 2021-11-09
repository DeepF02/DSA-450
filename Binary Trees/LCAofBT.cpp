// Find LCA in a Binary tree
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;
    Node(int val){
        data=val;
        left=right=NULL;
    }
};
class Solution {
    public:
    //Function to return the lowest common ancestor in a Binary Tree.
    Node* lca(Node* root ,int n1 ,int n2)
    {
        if(!root || root->data==n1 || root->data==n2)return root;
        Node* leftNode = lca(root->left, n1, n2);
        Node* rightNode = lca(root->right, n1, n2);
        if(leftNode && rightNode)return root;
        else if(!leftNode)return rightNode;
        else return leftNode;
    }
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

    Solution tree;
    int n1, n2;
    cin>>n1>>n2;
    Node* ans=tree.lca(root, n1, n2);
    cout<<ans->data<<endl;

    return 0;
}
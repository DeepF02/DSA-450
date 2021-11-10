// Convert Binary tree into Sum tree
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
    private:
    //preorder traversal works on Root Left Right.
    void preOrder(Node* root, vector<int>& preTree){
        if(!root) return; //if root is null then we simply return.
        preTree.push_back(root->data); //first, we store the data at root in a list.
        preOrder(root->left, preTree); //then we call the recursive function for left subtree.
        preOrder(root->right, preTree);//then we call the recursive function for right subtree.
    }

    int SumTree(Node *node)
    {
        if(!node)return 0;
        // Recursively call for left and right subtrees and store the sum as new value of this node  
        int leftSumTree=SumTree(node->left);
        int rightSumTree=SumTree(node->right);
        int childNode=node->data;// Store the old value
        node->data=leftSumTree + rightSumTree;
        // Return the sum of values of nodes in left and right subtrees and old_value of this node  
        return childNode + node->data;
    }
    public:
    // Convert a given tree to a tree where every node contains sum of values of nodes in left and right subtrees in the original tree
    void toSumTree(Node *node)
    {
        if(!node)return;
        SumTree(node);
        
        //This is code for converting Bt to sumtree without decreasing value of parent node or any node;
        /*if(!node)return;
        int child=0;
        if(node->left) child+=node->left->data;
        if(node->right) child+=node->right->data;
        if(node->data<=child)node->data=child;
        else {
            if(node->left) node->left->data=node->data;
            else if(node->right) node->right->data=node->data;
            // node->data*=2;
        }
        toSumTree(node->left);
        toSumTree(node->right);
        if(node->left && node->right)node->data=node->left->data + node->right->data;
        else if (node->left)node->data=node->left->data;
        else if (node->right)node->data=node->right->data;
        else node->data=0;
        int total=0;
        if(node->left) total+=node->left->data;
        if(node->right) total+=node->right->data;
        if(node->left || node->right)node->data=total;*/
    }//Time Complexity O(N) && Space Complexity O(H) 

    vector<int> preorderTraversal(Node* root) {
        vector<int> nodes;
        preOrder(root, nodes);
        return nodes;
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
    vector<int>ansBefore=tree.preorderTraversal(root);
    for(auto x:ansBefore)cout<<x<<" ";
    cout<<endl;
    tree.toSumTree(root);
    vector<int>ansAfter=tree.preorderTraversal(root);
    for(auto x:ansAfter)cout<<x<<" ";
    cout<<endl;

    return 0;
}
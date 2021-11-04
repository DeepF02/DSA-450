// Check if a tree is balanced or not
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
    //Function to find the valid height of a binary tree by ** Recursion **.
    int check(Node* root){
        if(!root)return 0;
        int lH = check(root->left);
        if(lH==-1)return -1; // if left heigth exceeds <1 we return -1
        int rH = check(root->right);
        if(rH==-1)return -1; // if right heigth exceeds <1 we return -1
        if(abs(lH-rH)>1)return -1;// if heigth exceeds <1 at any moment we return -1
        return max(lH, rH) +1;
    }
    public:
    //Function to check whether a binary tree is balanced or not.
    bool isBalanced(Node *root)
    {
        return check(root)!=-1;
    }//Time Complexity O(N) & Space Complexity O(N) {N->Nodes of tree}
    
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
    cout<<tree.isBalanced(root);
    cout<<endl;

    return 0;
}
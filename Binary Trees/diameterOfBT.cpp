// Find Diameter of a tree -> Diameter of a BT is longest path between 2 nodes
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
    // Function to find height of a tree */.
    int height(Node* root, int &maxD){
        if(!root)return 0;
        int lH = height(root->left, maxD);
        int rH = height(root->right, maxD);
        maxD=max(maxD, lH+rH);// We update Maximum diameter at each recursion call
        return max(lH, rH) +1;
    }
    public:
    // Function to return the diameter of a Binary Tree.
    int diameter(Node* root) {
        int maxDiameter=0;
        height(root, maxDiameter);
        return maxDiameter;
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
    cout<<tree.diameter(root);
    cout<<endl;

    return 0;
}
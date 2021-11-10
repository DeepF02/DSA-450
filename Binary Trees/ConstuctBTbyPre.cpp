// Construct Binary tree from Inorder and preorder traversal
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
    /* C++ program to construct tree using inorder and preorder traversals */
    
    private:
    //preorder traversal works on Root Left Right.
    void preOrder(Node* root, vector<int>& preTree){
        if(!root) return; //if root is null then we simply return.
        preTree.push_back(root->data); //first, we store the data at root in a list.
        preOrder(root->left, preTree); //then we call the recursive function for left subtree.
        preOrder(root->right, preTree);//then we call the recursive function for right subtree.
    }

    /* Recursive function to construct binary of size len from Inorder traversal in[] and Preorder traversal pre[]. 
    Initial values of inStrt and inEnd should be 0 and len -1. 
    The function doesn't do any error checking for cases where inorder and preorder do not form a tree */
    Node* constructTree(int pre[], int preStart, int preEnd, int in[], int inStart, int inEnd, map<int, int>& mp){
        //Base Condition 
        if(preStart>preEnd || inStart>inEnd)return NULL; /* If this node has no children then return */

        Node* root= new Node(pre[preStart]);//We create new node in memory of currNode root in recursive call
        int rootIndex=mp[root->data]; // we assign rootIndex for reference
        int numsLeft=rootIndex-inStart; // numsLeft stores no. of element before rootIndex
        //  Using rootIndex we pass starting & ending index of pre & in to construct left and right subtres's.
        root->left=constructTree(pre, preStart+1, preStart+numsLeft, in, inStart, rootIndex-1, mp);
        root->right=constructTree(pre, preStart+numsLeft+1, preEnd, in, rootIndex+1, inEnd, mp);
        return root;
    }

    public:// This function mainly creates an map, then calls constructTree()
    Node* buildTree(int in[],int pre[], int n)
    {
        // Store indexes of all nodes in map so that we can quickly find later
        map<int, int>mp;
        for(int i=0; i<n; i++) mp[in[i]]=i;
        
        Node* root = constructTree(pre, 0, n-1, in, 0, n-1, mp);
        return root;
    }//Time Complexity O(N) && Space Complexity O(H) 

    /* This function is here just to test buildTree() */
    vector<int> preorderTraversal(Node* root) {
        vector<int> nodes;
        preOrder(root, nodes);
        return nodes;
    } 
};

int32_t main()
{
    /* Binary tree to be Constructed is
            0
          /   \
         1     2
       /  \   /
      3    4 5
    */
    int in[] = {3, 1, 4, 0, 5, 2};
    int pre[] = {0, 1, 3, 4, 2, 5};

    Solution tree;
    Node* root = tree.buildTree(in, pre, 6);
    vector<int>ansAfter=tree.preorderTraversal(root);
    printf("Inorder traversal of the constructed tree is \n");
    for(auto x:ansAfter)cout<<x<<" ";
    cout<<endl;

    return 0;
}
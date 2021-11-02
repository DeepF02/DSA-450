// Preorder Traversal of a tree both using recursion and Iteration
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
    //Function to find the preorder traversal of the tree.
    
    //preorder traversal works on Root Left Right.
    void preOrder(Node* root, vector<int>& preTree){
        if(!root) return; //if root is null then we simply return.
        preTree.push_back(root->data); //first, we store the data at root in a list.
        preOrder(root->left, preTree); //then we call the recursive function for left subtree.
        preOrder(root->right, preTree);//then we call the recursive function for right subtree.
    }
public:
    //Function to return a list containing the preorder traversal of the tree *** RECURSIVELY ***.
    vector<int> preorderTraversal(Node* root) {
        vector<int> nodes;
        preOrder(root, nodes);
        return nodes;
    } //Time complexity O(nodes) //space complexity can be constant

    //Function to return a list containing the preorder traversal of the tree ** Iteratively **.
    void preorderIterative(Node* root){
        if(!root)return;
        stack<Node*> nodeSk;
        Node* currNode=root;// start from root node (set current node to root node)
        // run till stack is not empty or current is not NULL
        // Method 1
        // while(!nodeSk.empty() || currNode){
        //     // Print left children while exist and keep pushing right into the stack.
        //     while(currNode){
        //         cout<<currNode->data<<" ";
        //         if(currNode->right) nodeSk.push(currNode->right);
        //         currNode=currNode->left;
        //     }
        //     // We reach when curr is NULL, so We take out a right child from stack
        //     if(!nodeSk.empty()){
        //         currNode=nodeSk.top();
        //         nodeSk.pop();
        //     }
        // }
        //Optimising Method 1 **Method 2**
        nodeSk.push(currNode);
        while(!nodeSk.empty()){
            currNode=nodeSk.top();
            nodeSk.pop();
            if(currNode->right) nodeSk.push(currNode->right);
            if(currNode->left) nodeSk.push(currNode->left);
            cout<<currNode->data<<" ";
        }
    }//Time complexity O(nodes) //space complexity O(H) (H-height of tree)

    //There is also One more type of Traversal Called Morris Traversal its disadvantage is it modifies the tree while traversing. 
    void preorderMorris(Node* root){
        // if(!root)return;
        while(root){
            if(root->left){
                Node* pre=root->left;
                while(pre->right && pre->right!=root){
                    pre=pre->right;
                }
                if(!pre->right){
                    pre->right=root;
                    cout<<root->data<<" ";
                    root=root->left;
                }else{
                    pre->right=NULL;
                    root=root->right;
                }
            }
            else{
                cout<<root->data<<" ";
                root=root->right;
            }
        }
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
    vector<int>ans=tree.preorderTraversal(root);
    for(auto x:ans)cout<<x<<" ";
    cout<<endl;
    tree.preorderIterative(root);
    cout<<endl;
    tree.preorderMorris(root);

    return 0;
}
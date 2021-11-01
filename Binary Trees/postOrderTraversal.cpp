// Postorder Traversal of a tree both using recursion and Iteration
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
    //Function to find the postorder traversal of the tree.
    
    //postorder traversal works on Root Left Right.
    void postOrder(Node* root, vector<int>& postTree){
        if(!root) return; //if root is null then we simply return.
        postOrder(root->left, postTree); //first, we call the recursive function for left subtree.
        postOrder(root->right, postTree);//then we call the recursive function for right subtree.
        postTree.push_back(root->data); //then we store the data at root in a list.
    }
public:
    //Function to return a list containing the postorder traversal of the tree *** RECURSIVELY ***.
    vector<int> postorderTraversal(Node* root) {
        vector<int> nodes;
        postOrder(root, nodes);
        return nodes;
    } //Time complexity O(nodes) //space complexity can be constant

    //Function to return a list containing the postorder traversal of the tree ** Iteratively **.
    void postorderIterative(Node* root){
        if(!root)return;
        stack<Node*> nodeSk;
        Node* currNode=root;// start from root node (set current node to root node)
        Node* last=NULL;
        // run till stack is not empty or current is not NULL
        while(!nodeSk.empty() || currNode){
            // Print left children while exist and keep pushing right into the stack.
            if(currNode){
                nodeSk.push(currNode);
                currNode=currNode->left;
            }
            else{
                Node* prev=nodeSk.top();
                if(prev->right && last!=prev->right)currNode=prev->right;
                else{
                    cout<<prev->data<<" ";
                    last=prev;
                    nodeSk.pop();
                } 
            }
        }
    }//Time complexity O(nodes) //space complexity O(H) (H-height of tree)

    //There is also One more type of Traversal Called Morris Traversal its disadvantage is it modifies the tree while traversing. 
    // void postorderMorris(Node* root){
    // }
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
    vector<int>ans=tree.postorderTraversal(root);
    for(auto x:ans)cout<<x<<" ";
    cout<<endl;
    tree.postorderIterative(root);
    cout<<endl;
    // tree.postorderMorris(root);

    return 0;
}
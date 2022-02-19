//Deletion of a node in a BST
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
private:
    // Function to help connect prevNode of deleted Note to its left/right Node
    Node* helper(Node* root) {
        if(!root->left)return root->right;
        else if(!root->right)return root->left;
        Node* rightNode =root->right;
        Node* lastRight = findLast(root->left);
        lastRight->right=rightNode;// connect right of last right node to right subtree.
        return root->left;
    }
    // Function to find last right node of left/right subtree of key node
    Node* findLast(Node* root) {
        if(!root->right)return root;
        return findLast(root->right);
    }
public:
    // Function to delete a Node from given BST
    Node* deleteNode(Node* root, int key) {
        if(!root)return root;
        if(root->val==key) return helper(root);
        Node* dummy =root;
        while(root){
            if(root->val>key){
                if(root->left && root->left->val==key){
                    root->left=helper(root->left);
                    break;
                }
                else root=root->left;
            }else{
                if(root->right && root->right->val==key){
                    root->right=helper(root->right);
                    break;
                }
                else root=root->right;
            }
        }
        return dummy;
    }//Time Complexity: The worst-case time complexity of search and insert operations is O(h) && Space is constant


    //Utility Function to return the level order traversal of a BST.
    vector<int> levelOrder(Node *root){
        vector<int> ans;
        queue<Node*> q;
        if (root)q.push(root);
        while (!q.empty()){
            Node *node = q.front();
            q.pop();
            if (node->left)q.push(node->left);
            if (node->right)q.push(node->right);
            ans.push_back(node->val);
        }
        return ans;
    }
};

int32_t main()
{
    /* Constructed binary tree is
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
    root=BST.deleteNode(root, 10);
    vector<int> ans = BST.levelOrder(root);
    for (auto x : ans)cout << x << " ";
    cout << endl;

    return 0;
}
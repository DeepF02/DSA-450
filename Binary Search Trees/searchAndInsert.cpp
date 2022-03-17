//Find a value in a BST if doesn't exist create it.
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
    // Function to insert a node in a BST.
    Node *insert(Node *root, int val){
        Node *left = NULL, *right = NULL;
        if (!root){ // If root doesn't exist in BST we insert it. 
            Node *newNode = new Node(val);
            return newNode;
        }
        if (root->data == val)return root; // If root exist tehn we simply retrun root
        if (root->data > val)root->left = insert(root->left, val); // If val is less then root it will be present in left subtree
        if (root->data < val)root->right = insert(root->right, val); // If val is greater then root it will be present in right subtree
        return root;
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
            ans.push_back(node->data);
        }
        return ans;
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
    root=BST.insert(root, 35);
    vector<int> ans = BST.levelOrder(root);
    for (auto x : ans)cout << x << " ";
    cout << endl;

    return 0;
}
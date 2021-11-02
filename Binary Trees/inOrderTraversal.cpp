// INorder Traversal of a tree both using recursion and Iteration
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
private:
    //Function to find the inorder traversal of the tree.

    //InOrder traversal works on Left Root Right.
    void inOrder(Node *root, vector<int> &inTree)
    {
        if (!root)
            return;                   //if root is null then we simply return.
        inOrder(root->left, inTree);  //We call the recursive function for left subtree.
        inTree.push_back(root->data); //we store the data at root in a list.
        inOrder(root->right, inTree); //then we call the recursive function for right subtree.
    }

public:
    //Function to return a list containing the preorder traversal of the tree *** RECURSIVELY ***.
    vector<int> inorderTraversal(Node *root)
    {
        vector<int> nodes;
        inOrder(root, nodes);
        return nodes;
    } //Time complexity O(nodes) //space complexity can be constant

    //Function to return a list containing the preorder traversal of the tree ** Iteratively **.
    void inorderIterative(Node *root)
    {
        if (!root)
            return;
        stack<Node *> nodeSk;
        Node *currNode = root; // start from root node (set current node to root node)
        // while(!nodeSk.empty() || currNode){
        //     // Print left children while exist and keep pushing right into the stack.
        //     while(currNode){
        //         nodeSk.push(currNode);
        //         currNode=currNode->left;
        //     }
        //     // We reach when currNode i.e left node is NULL, so print root node from stack and move to right node
        //     currNode=nodeSk.top();
        //     nodeSk.pop();
        //     cout<<currNode->data<<" ";
        //     currNode=currNode->right;
        // }
        //Optimising Method 1 **Method 2**
        while (true)
        {
            if (currNode)
            {
                nodeSk.push(currNode);
                currNode = currNode->left;
            }
            else
            {
                if(nodeSk.empty())break;    
                currNode=nodeSk.top();
                nodeSk.pop();
                cout << currNode->data << " ";
                currNode=currNode->right;
            }
        }
    } //Time complexity O(nodes) //space complexity O(H) (H-height of tree)

    //There is also One more type of Traversal Called Morris Traversal its disadvantage is it modifies the tree while traversing.
    // void inorderMorris(Node *root)
    // {
    //     // if(!root)return;
    //     while (root)
    //     {
    //         if (root->left)
    //         {
    //             Node *pre = root->left;
    //             while (pre->right && pre->right != root)
    //             {
    //                 pre = pre->right;
    //             }
    //             if (!pre->right)
    //             {
    //                 pre->right = root;
    //                 root = root->left;
    //             }
    //             else
    //             {
    //                 pre->right = NULL;
    //                 cout << root->data << " ";
    //                 root = root->right;
    //             }
    //         }
    //         else
    //         {
    //             cout << root->data << " ";
    //             root = root->right;
    //         }
    //     }
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
    Node *root = new Node(10);
    root->left = new Node(20);
    root->right = new Node(30);
    root->left->left = new Node(40);
    root->left->left->left = new Node(70);
    root->left->right = new Node(50);
    root->right->left = new Node(60);
    root->left->left->right = new Node(80);

    Solution tree;
    vector<int> ans = tree.inorderTraversal(root);
    for (auto x : ans)
        cout << x << " ";
    cout << endl;
    tree.inorderIterative(root);
    cout << endl;
    // tree.inorderMorris(root);
    return 0;
}
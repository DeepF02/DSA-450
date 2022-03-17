// Flatten BST to sorted list
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
    // Function to perform in-order traversal "recursively"
    void inOrderToLL(Node *root, Node*& prev)
    {
        if (!root) return;            // if root is null then we simply return.
        inOrderToLL(root->left, prev);  // We call the recursive function for left subtree.
        prev->right= root; // we store right of prev node to curr
        prev->left=NULL; // And pount its left to NULL
        prev=root; // ANd intialse prev to curr root
        inOrderToLL(root->right, prev); // then we call the recursive function for right subtree.
    }

public:
    // Function to flatten binary tree using inOrder traversal
    Node* flattenBSToLL(Node* root)
    {
        Node* dummy = new Node(-1); //We craete a dummy node to act as our new head node
        Node* prev=dummy; // we poin tprev to dummy
        inOrderToLL(root, prev);
        // now prev is pointing to last node of BST so we amke sure its right & left are NULL
        prev->left=NULL;
        prev->right=NULL;
        // We make a new head pointer to return the starting node of linkedlist
        Node* head=dummy->right;
        delete dummy; //We delete the dummy node
        return head;
    } //Time complexity O(nodes) & space complexity is O(nodes);

    //Function to print a linked list ITERATIVE.
    void print(Node* head){
        while(head){
            cout<<head->data<<" ";
            head=head->right;
        }
    }
};

int32_t main()
{
    /* Constructed Binary Search tree is
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

    Solution tree;
    Node* head = tree.flattenBSToLL(root);
    tree.print(head);
    cout << endl;
    // tree.inorderMorris(root);
    return 0;
}
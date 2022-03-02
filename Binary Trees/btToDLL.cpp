// Convert Binary tree into Doubly Linked List
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
    public:
    //this variables be our prev & head of DLL and we need to update them in recursion calls that's why we declare them globaly
    Node *prev=NULL, *head=NULL;
    // Function to convert binary tree to doubly linked list and return it.
    Node * bToDLL(Node *root)
    {
        // your code here
        if(!root) return NULL;
        bToDLL(root->left);
        if(!prev)head=root; // when we start the inorder traversal and reach last left node that will be head node of our DLL
        else{
            root->left=prev; // we just upadte left part of BT to make it prev of DLL cause we use right pointer for inorder traversal
            prev->right=root; // we update right part of prev to curr;
        }
        prev=root; // prev node will be updated to curr node
        bToDLL(root->right);
        return head;
    }
    //Time Complexity O(N) Auxillary Space O(1)
    
    // Utility Function to print the inorder traversal of BT.
    void inOrderPrint(Node *root)
    {
        if (!root) return;
        inOrderPrint(root->left);
        cout<< (root->data)<<" ";
        inOrderPrint(root->right);
    }

    // Utility Function to print a Doubly linked list ITERATIVE.
    void printDLL(Node* root){
        while(root){
            cout<<root->data<<" ";
            root=root->right;
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
    tree.inOrderPrint(root);
    cout<<endl;
    Node *head=tree.bToDLL(root);
    tree.printDLL(head);
    cout<<endl;

    return 0;
}
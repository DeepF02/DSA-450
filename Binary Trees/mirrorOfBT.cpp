// Mirror  of BT
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
    //preorder traversal works on Root Left Right.
    void preOrder(Node* root, vector<int>& preTree){
        if(!root) return; //if root is null then we simply return.
        preTree.push_back(root->data); //first, we store the data at root in a list.
        preOrder(root->left, preTree); //then we call the recursive function for left subtree.
        preOrder(root->right, preTree);//then we call the recursive function for right subtree.
    }
    public:
    //Function to find the mirror of a binary tree by ** Recursion **.
    Node* mirror(struct Node* root){
        if(root){
            mirror(root->left);
            mirror(root->right);
            swap(root->left, root->right);
        }
        return root;
    } //Time Complexity O(N) & Space Complexity O(H) {H->heigth of tree}

    //Function to find the mirror of a binary tree by ** Iterative **.
    // Node* mirror(struct Node* root){
    //     stack<Node*>s;
    //     if(root)s.push(root);
    //     while(!s.empty()){
    //         Node* p=s.top();
    //         s.pop();
    //         if(p->left)s.push(p->left);
    //         if(p->right)s.push(p->right);
    //         swap(p->left, p->right);
    //     }
    //     return root;
    // } //Time Complexity O(N) & Space Complexity O(H) {H->heigth of tree}

    
    //Function to return a list containing the preorder traversal of the tree *** RECURSIVELY ***.
    vector<int> preorderTraversal(Node* root) {
        vector<int> nodes;
        preOrder(root, nodes);
        return nodes;
    } //Time complexity O(nodes) //space complexity can be constant
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
    tree.mirror(root);
    vector<int>newAns=tree.preorderTraversal(root);
    for(auto x:newAns)cout<<x<<" ";
    cout<<endl;

    return 0;
}
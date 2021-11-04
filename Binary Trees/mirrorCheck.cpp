// Check if 2 trees are mirror or not
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

/* Given two trees, should return true if they are mirror of each other. */
class Solution
{
    public:
    // function to check if two tree are mirror of each other ***Recursively***
    int areMirror(Node* a, Node* b) {
        if(!a || !b) return (a==b);
        else if(a->data!=b->data) return false;
        return areMirror(a->left, b->right) && areMirror(a->right, b->left);
    }
    //Same problem with a variation Check Mirror in N-ary tree
    int checkMirrorTree(int n, int e, int A[], int B[]) {
        // LOOK into this once again
        map<int,vector<int>>m1,m2;
        for(int i=0;i<2*e;i+=2)
            m1[A[i]].push_back(A[i+1]);
        for(int i=0;i<2*e;i+=2) 
            m2[B[i]].push_back(B[i+1]);
        for(auto it:m1)
        {
            vector<int>t=it.second;
            reverse(t.begin(),t.end());
            m1[it.first]=t;
        }
        return m1==m2;
    }
    //Time Complexity O(N)
    //Space Complexity O(N)
};

int32_t main()
{
    /* Constructed binary tree is
        A=    1    B= 1
            /  \     / \
          2     3   3   2 
         /  \         /  \ 
       4    5        5   4
    */
    
    Node *a = new Node(1);
    Node *b = new Node(1);
    a->left = new Node(2);
    a->right = new Node(3);
    a->left->left  = new Node(4);
    a->left->right = new Node(5);
 
    b->left = new Node(3);
    b->right = new Node(2);
    b->right->left = new Node(5);
    b->right->right = new Node(4);
    Solution tree;
    (tree.areMirror(a, b))?cout<<"Trees are mirror of each other\n":cout<<"Trees are not mirror of each other\n";

    return 0;
}
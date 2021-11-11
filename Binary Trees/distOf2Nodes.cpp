// Find distance between 2 nodes in a Binary tree
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
    //Function to return the lowest common ancestor in a Binary Tree.
    Node* LCA(Node* root ,int n1 ,int n2)
    {
        if(!root || root->data==n1 || root->data==n2)return root;
        Node* leftNode = LCA(root->left, n1, n2);
        Node* rightNode = LCA(root->right, n1, n2);
        if(leftNode && rightNode)return root;
        else if(!leftNode)return rightNode;
        else return leftNode;
    }
    // formula to find distance betn 2 nodes is *** Dist(n1, n2) = Dist(root, n1) + Dist(root, n2) - 2*Dist(root, lca) ***
    // Updated formula to find distance betn 2 nodes is *** Dist(n1, n2) = Dist(lca, n1) + Dist(lca, n2) *** lca is lca(n1,n2)
    
    // distance of one node to root node is lvl of that particular node
    // Iterative way to get lvl 
    // int getLevel(Node *root, int x){
    //     queue<pair<Node*, int>>q;
    //     if(root)q.push({root, 0});
    //     while(!q.empty()){
    //         int n=q.size();
    //         auto p=q.front();
    //         q.pop();
    //         int lvl=p.second;
    //         if(p.first->data==x)return lvl;
    //         if(p.first->left)q.push({p.first->left, lvl+1});
    //         if(p.first->right)q.push({p.first->right, lvl+1});
    //     }
    //     return 0;
    // }

    // Recursive way to get lvl 
    int getLevel(Node* root, int k, int lvl){
        if(!root)return -1;
        if(root->data==k)return lvl;
        int l=getLevel(root->left, k, lvl+1);
        return (l!=-1)?l:getLevel(root->right, k, lvl+1);
    }
    /* Should return minimum distance between a and b in a tree with given root*/
    int findDist(Node* root, int a, int b) {
        // Your code here
        if(!root)return -1;
        int ans=0;
        Node* lcaNode=LCA(root, a, b);
        int d1=getLevel(lcaNode, a, 0);
        int d2=getLevel(lcaNode, b, 0);
        ans=d1 +d2;
        return ans;
    }
    //Time Complexity O(N)
    //Space Complexity O(H) -> H is height of BT
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
    int n1, n2;
    cin>>n1>>n2;
    int ans=tree.findDist(root, n1, n2);
    cout<<ans<<endl;

    return 0;
}
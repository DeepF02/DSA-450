// Boundary traversal of a Binary tree
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
    void  addLeftBoundary(Node* root, vector<int>&ans){
        if(!root)return;
        while(root->left || root->right){
            ans.push_back(root->data);
            if(!root->left && !root->right)break;
            if(root->left)root=root->left;
            else if(root->right)root=root->right;
        }
    }
    void  addLeafs(Node* root, vector<int>&ans){
        if(!root)return;
        addLeafs(root->left, ans);
        if(!root->left && !root->right)ans.push_back(root->data);
        addLeafs(root->right, ans);
    }
    void  addRightBoundary(Node* root, vector<int>&ans){
        if(!root)return;
        stack<int>s;
        while(root->left || root->right){
            s.push(root->data);
            if(!root->left && !root->right)break;
            if(root->right)root=root->right;
            else if(root->left)root=root->left;
        }
        while(!s.empty()){
            ans.push_back(s.top());
            s.pop();
        }
    }
    public:
    //Function to store the boundary traversal of tree in a list.
    vector <int> boundary(Node *root)
    {
        vector<int>ans;
        if(!root)return ans;
        ans.push_back(root->data);
        addLeftBoundary(root->left, ans);
        addLeafs(root, ans);
        addRightBoundary(root->right, ans);
        return ans;
    }
    //Time Complexity O(N)
    //Space Complexity O(N*N)
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
    vector<int>ans=tree.boundary(root);
    for(auto x:ans)cout<<x<<" ";
    cout<<endl;

    return 0;
}
// Right View of a Binary Tree
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
    void rightSideView(Node* root,int lvl, vector<int>&ans){
        if(!root)return;
        if(ans.size()==lvl)ans.push_back(root->data); //If arr size is same as lvl i.e. we have reached this lvl for first time.
        rightSideView(root->right, lvl+1, ans);//First we go right and increase lvl by 1  
        rightSideView(root->left, lvl+1, ans);//Then we go left and increase lvl by 1 
    }
    public:
    //Function to return a list of nodes visible from the Right view from top to bottom in Binary Tree ***Recursively***.
    vector<int> rightView(Node* root) {
        vector<int>ans;
        rightSideView(root, 0, ans);
        return ans;
    }// this function consumes less space then iterative function
    //Time Complexity O(N) && Space Complexity O(H) 

    //Function to return a list of nodes visible from the Right view from top to bottom in Binary Tree ***Iterative***.
    // vector<int> rightView(Node *root)
    // {
    //     vector<int>ans;
    //     //creating a map to store nodes at a particular level (height).
    //     map<int, int>nodes; // nodes[level]=data;
    //     queue<pair<Node*, int>>q; // q={currNode, level};
    //     if(root)q.push({root, 0});
    //     // We traverse the tree in level order traversal
    //     while(!q.empty()){
    //         auto p=q.front();
    //         q.pop();
    //         Node* currNode=p.first;
    //         int lvl=p.second; // this stores level of tree
    //         //This will keep on pushing new data to a key if it exist i.e the last element of that key representing level of BT 
    //         nodes[lvl]=(currNode->data);
            
    //         if(currNode->left)q.push({currNode->left, lvl+1});
    //         if(currNode->right)q.push({currNode->right, lvl+1});
    //     }
    //     //traversing the map and storing the nodes in list at every level.
    //     for(auto i: nodes) ans.push_back(i.second);
        
    //     return ans;
    // }
    //Time Complexity O(N)
    //Space Complexity O(N)
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
    vector<int>ans=tree.rightView(root);
    for(auto x:ans)cout<<x<<" ";
    cout<<endl;

    return 0;
}
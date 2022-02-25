// Diagnol Traversal of a Binary tree
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
    //Function to store the Diagonal traversal of tree in a list.
    vector<int>diagonal(Node *root)
    {
        vector<int>ans;
        if(!root) return ans;
        queue<Node*>q;
        q.push(root);
        while(!q.empty()){
            Node* currNode=q.front();
            q.pop(); // pop the node once we done visiting it
            //So the idea is to go right untill we reach leaf node then we go back to left node stored in queue
            while(currNode){
                ans.push_back(currNode->data); //move currnode to ans
                if(currNode->left)q.push(currNode->left);//store all the left nodes in the queue
                currNode=currNode->right; // move to right node
            }
        }
        return ans;
    }
    //Time Complexity O(N)
    //Auxillary Space O(N)
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
    vector<int>ans=tree.diagonal(root);
    for(auto x:ans)cout<<x<<" ";
    cout<<endl;

    return 0;
}
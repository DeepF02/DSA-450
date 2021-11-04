//Sum of Nodes on the Longest path from root to leaf node 
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
    // function to find the sum of nodes on the longest path from root to leaf node
    int ans=0, maxLvl=1;
    void maxHeight(Node* root, int lvl, int sum){
        if(!root)return;
        if(lvl>maxLvl){// if we reach new max height
            ans=sum+root->data;
            maxLvl=lvl;
        }
        else if(lvl==maxLvl)ans=max(ans, sum+root->data);//if two heights are same
        maxHeight(root->left, lvl + 1, sum + root->data);
        maxHeight(root->right, lvl + 1, sum + root->data);
    }
    public:
    // utility function to find the sum of nodes on the longest path from root to leaf node
    int sumOfLongRootToLeafPath(Node *root)
    {
        maxHeight(root,1,0);
        return ans;
    }
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
    cout << "Sum = "<< tree.sumOfLongRootToLeafPath(root);
    cout<<endl;

    return 0;
}
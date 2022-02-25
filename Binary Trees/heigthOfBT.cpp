// Height  of BT
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
    //Function to find the height of a binary tree by ** Recursion **.
    int height(struct Node* node){
        // code here
        if(!node)return 0;
        int ans= 1+ max(height(node->left), height(node->right));
        return ans;
    } //Time Complexity O(N) & Space Complexity O(H) {H->heigth of tree}
    
    //Function to find the height of a binary tree by ** Iterative **.
    int heightByLvlOrder(Node* root)
    {
        int ans=0;
        queue<Node*>q;
        if(root)q.push(root);
        while(!q.empty()){
            int n=q.size();
            ans++;
            while(n--){
                Node* node=q.front();
                q.pop();
                if(node->left)q.push(node->left);
                if(node->right)q.push(node->right);
            }
        }
        return ans;
    } //Time Complexity O(N) & Space Complexity O(N) {N->Nodes of tree}
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
    cout<<tree.height(root);
    cout<<endl;
    cout<<tree.heightByLvlOrder(root);

    return 0;
}
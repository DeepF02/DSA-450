// Preorder, InOder & Postorder Traversal of a Binary tree in one function
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
class Solution{
public:
    vector<int>preInPost(Node* root){
        vector<int>Pre, In, post;
        // vector<vector<int>>pip(7);
        if(!root)return Pre;
        stack<pair<Node*, int>>st;
        st.push({root, 1});
        while(!st.empty()){
            auto it = st.top();
            st.pop(); 
            // int one=0, two=0, three=0;
            //for Preorder increment 1 to 2 and push left of subtree
            if(it.second==1){
                Pre.push_back(it.first->data);
                // pip[one++].push_back(it.first->data);
                it.second++;
                st.push(it);
                if(it.first->left)st.push({it.first->left,1});
            }
            //for Inorder increment 2 to 3 and push left of subtree
            else if(it.second==2){
                In.push_back(it.first->data);
                // pip[two++].push_back(it.first->data);
                it.second++;
                st.push(it);
                if(it.first->right)st.push({it.first->right,1});
            }
            //We just need to push_back our ans
            else{
                post.push_back(it.first->data);
                // st.pop();
                // pip[three++].push_back(it.first->data);
            }
        }
        return In;
    }
    //Time complexity O(3*N) //space complexity O(3*N<->4*N)
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
    vector<int>ans=tree.preInPost(root);
    for(auto x:ans)cout<<x<<" ";
    // for(int i=0; i<3; i++){
    //     for(int j=0; j<7; j++){
    //         cout<<ans[j][i]<<" ";
    //     }
    //     cout<<endl;
    // }
    // cout<<endl;
    // tree.preorderIterative(root);
    // cout<<endl;
    // tree.preorderMorris(root);

    return 0;
}
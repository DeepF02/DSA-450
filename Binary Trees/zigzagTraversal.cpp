// Zig-Zag level order traversal of BT
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
    //Function to store the zig zag order traversal of tree in a list.
    vector <int> zigZagTraversal(Node* root)
    {
    	// Code here
    	vector<int>ans;
    	queue<Node*>q;
    	bool leftToRight=true;
    	if(root)q.push(root);
    	while(!q.empty()){
    	    int n=q.size();
    	    if(!leftToRight){
    	        while(n--){
    	            Node* ptr=q.front();
    	            q.pop();
    	            if(ptr->right)q.push(ptr->right);
    	            if(ptr->left)q.push(ptr->left);
    	            ans.push_back(ptr->data);
    	        }
    	    }
    	    else{
    	        stack<int>s;
    	        while(n--){
    	            Node* ptr=q.front();
    	            q.pop();
    	            if(ptr->right)q.push(ptr->right);
    	            if(ptr->left)q.push(ptr->left);
    	            s.push(ptr->data);
    	        }
    	        while(!s.empty()){
    	            ans.push_back(s.top());
    	            s.pop();
    	        }
    	    }
    	    leftToRight=!leftToRight;
    	}
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
    vector<int>ans=tree.zigZagTraversal(root);
    for(auto x:ans)cout<<x<<" ";
    cout<<endl;

    return 0;
}
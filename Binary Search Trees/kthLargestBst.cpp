//Find Kth largest element in a BST.
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};
class Solution
{
public:
    /* Idea is to get inorder travelsal of BST 
    **{Note: Inorder Travsel of BST is always in soted order}**
       We keep a counter and increment it each time we print/push node through inorder travesal
       here the kth largest element is nothing but (N-k+1)th smallest element where n is no. of nodes
       If counter == K its the kth smallest node we require!!
    */
   //So we traverse 2 times one to get no. of nodes and then to get (N-K+1)th smallest element. 
    int inorderTraversal(Node *root, int k){
        if(!root) return 0;
        stack<Node*>s;
        int cnt=0;
        Node* currNode=root;
        while(true){
            if(currNode){
                s.push(currNode);
                currNode=currNode->left;
            }
            else{
                if(s.empty())break;
                currNode=s.top();
                s.pop();
                cnt++;
                if(k!=-1 && cnt==k) return currNode->data;
                currNode=currNode->right;
            }
        }
        return cnt;
    }
    
    // Function to get kth largest element node in a BST.
    int kthLargest(Node *root, int K)
    {
        int n=inorderTraversal(root, -1);
        return inorderTraversal(root, n+1-K);
    }// Time complexity O(N) & Auxillary Space complexity O(N);
    //Recursive traversal will have same complexities only morris traversal will have space const rest TC wiil be O(N);
};

int32_t main()
{
    /* Constructed binary tree is
              20
            /   \
          10     30
         /  \   /
        4   12 25
      /  \
     3   5
    */
    Node *root = new Node(20);
    root->left = new Node(10);
    root->right = new Node(30);
    root->left->left = new Node(4);
    root->left->left->left = new Node(3);
    root->left->right = new Node(12);
    root->right->left = new Node(25);
    root->left->left->right = new Node(5);

    Solution BST;
    int k=3;
    cout<<k<<"th largets element of given BST is "<<BST.kthLargest(root, k)<<endl;

    return 0;
}
// inorder traversal is 3 4 5 10 12 20 25 30
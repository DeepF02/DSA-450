void postorderIterative(Node* root){
        if(!root)return;
        stack<Node*> nodeSk;
        Node* currNode=root;// start from root node (set current node to root node)
        Node* last=NULL;
        // run till stack is not empty or current is not NULL
        while(!nodeSk.empty() || currNode){
            // Print left children while exist and keep pushing right into the stack.
            if(currNode){
                nodeSk.push(currNode);
                currNode=currNode->left;
            }
            else{
                Node* prev=nodeSk.top();
                if(prev->right && last!=prev->right)currNode=prev->right;
                else{
                    cout<<prev->data<<" ";
                    last=prev;
                    nodeSk.pop();
                } 
            }
        }
    }//T
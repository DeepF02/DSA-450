or<int> leftView(Node *root)
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
    //         //If this level key doesn't exist (i.e. its 0 or traversed the first time) then only we push data
    //         if(!nodes[lvl])nodes[lvl]=(currNode->data);
            
    //         if(currNode->left)q.push({currNode->left, lvl+1});
    //         if(currNode->right)q.push({currNode->right, lvl+1});
    //     }
    //     //traversing the map and storing the nodes in list at every level.
    //     for(auto i: nodes) ans.push_back(i.second);
        
    //     return ans;
    // }
class Solution{
  public:
    void helper(Node* root, unordered_map<int,bool> &vis, bool &ans){
        if(root == 0){
            return;
        }
        
        vis[root->data] = true;
        if(root->right == 0 && root->left == 0){
            int g = root->data + 1;
            int s = root->data - 1  == 0 ? root->data : root->data - 1;
            
            if(vis.find(g) != vis.end() &&
                vis.find(s) != vis.end()){
                    ans = true;
                    return;
                }
        }
        
        
        helper(root->left, vis, ans);
        helper(root->right, vis, ans);
        
    }
    bool isDeadEnd(Node *root)
    {
        unordered_map<int, bool> mp;
        bool ans = false;
        
        helper(root, mp, ans);
        
        return ans;
    }
};

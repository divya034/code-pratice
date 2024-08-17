class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*> q;
        vector<vector<int>> ans;
        if(root == NULL){
            return ans;
        }
        q.push(root);

        while(!q.empty()){
           int n = q.size();
           vector<int>level;

           for(int i = 0; i<n; i++){
            TreeNode* frontele = q.front();
            q.pop();
            if(frontele->left){
                q.push(frontele->left);
            }
            
            if(frontele->right){
                q.push(frontele->right);
            }

            level.push_back(frontele->val);
           }

           ans.push_back(level);
        }

        return ans;
    }
};

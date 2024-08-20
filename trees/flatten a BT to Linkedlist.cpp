class Solution {
public:
    void solve(TreeNode* root, vector<TreeNode*> &ans){
        if(root == NULL) return;

        ans.push_back(root);
        solve(root->left, ans);
        solve(root->right, ans);
    }
    void flatten(TreeNode* root) {
        if(root == NULL){
            return;
        }
        vector<TreeNode*> ans;
        solve(root, ans);

        for(int i = 0; i<ans.size()-1;i++){
            ans[i]->right = ans[i+1];
            ans[i]->left = NULL;
        }

    }
};

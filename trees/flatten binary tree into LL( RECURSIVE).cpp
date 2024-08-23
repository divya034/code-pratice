class Solution {
public:
    void solve(TreeNode* curr, TreeNode* &prev){
    
        if(curr == nullptr){
            return;
        }

        solve(curr->right, prev);
        solve(curr->left, prev);

        curr->right = prev;
        curr->left = nullptr;
        prev = curr;

    }

    void flatten(TreeNode* root) {
        TreeNode* curr = root;
        TreeNode* prev = nullptr;
        
        solve(curr, prev);
        
    }
};

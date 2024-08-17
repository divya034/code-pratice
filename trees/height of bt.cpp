class Solution {
public:
    int solve(TreeNode* &root, int &h){
        if(root == nullptr){
            return 0;
        }

        int left = solve(root->left, h);
        int right = solve(root->right, h);
        h = 1 + max(left, right);
        
        return h;

    }
    int maxDepth(TreeNode* root) {
        if(root == nullptr){
            return 0;
        }

        int h = 0;
        solve(root, h);

        return h;
    }
};

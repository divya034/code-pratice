class Solution {
public:
    void solve(TreeNode* root, long long sum, int &count, int target){
         if (root == NULL) {
            return;
        }
        
        sum += root->val;

        // Check if the current sum equals the target
        if (sum == target) {
            count++;
        }

        // Recur for left and right subtrees
        solve(root->left, sum, count, target);
        solve(root->right, sum, count, target);

    }

    void traverse(TreeNode* root, int &count, long long target) {
        if (root == NULL) {
            return;
        }

        // Solve for paths starting from the current root
        solve(root, 0, count, target);

        // Traverse the left and right subtrees
        traverse(root->left, count, target);
        traverse(root->right, count, target);
    }

    int pathSum(TreeNode* root, long long targetSum) {
        int c = 0;
        
        traverse(root, c, targetSum);

        return c;
    }
};

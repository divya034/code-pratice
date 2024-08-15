class Solution {
public:
    void solve(vector<vector<int>> &ans, TreeNode* root, int target, int sum, vector<int> curr){
        if(root == NULL){
            return;
        }

        sum = sum + root->val;
        curr.push_back(root->val);

        if(root->left == NULL && root->right == NULL){
            if(sum == target){
                ans.push_back(curr);
            }
            else{
                return;
            }
        }
        solve(ans, root->left, target, sum, curr);
        solve(ans, root->right, target, sum, curr);

        return;
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        vector<int> curr;
        solve(ans, root, targetSum, 0, curr);

        return ans;
    }
};

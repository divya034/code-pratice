/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root == nullptr) return ans;

        queue<TreeNode*> q;
        q.push(root);


        while(!q.empty()){
            vector<int> level;
            int n = q.size();

            for(int i = 0; i<n; i++){
                TreeNode* fr = q.front();
                q.pop();
                level.push_back(fr->val);

                if(fr->left){
                    q.push(fr->left);
                }

                if(fr->right){
                    q.push(fr->right);
                }
            }

            ans.push_back(level);
        }
     return ans;
    }
};

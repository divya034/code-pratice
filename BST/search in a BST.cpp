class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        TreeNode* curr = root;

        while(curr != nullptr){
            if(curr->val == val){
                return curr;
            }

            else if(curr->val < val){
                curr = curr->right;
            }

            else{
                curr = curr->left;
            }
        }

        return nullptr;
    }
};

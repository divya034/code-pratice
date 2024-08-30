Best Case: O(log N) 
Space Complexity: O(1)
class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(root == nullptr) return new TreeNode(val);

        TreeNode* curr = root;

        while(true){
            if(curr->val > val){
                if(curr->left != NULL)
                    curr = curr->left;
                else{
                    curr->left = new TreeNode(val);
                    break;
                }
            }
            else{
                if(curr->right != NULL){
                    curr = curr->right;
                }
                else{
                    curr->right = new TreeNode(val);
                    break;
                }
            }
        }

        return root;
    }
};

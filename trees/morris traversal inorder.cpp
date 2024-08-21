class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        TreeNode* curr = root;

        while(curr != NULL){
            if(curr->left == NULL){
                ans.push_back(curr->val);
                curr = curr->right;
            }
            else{
                TreeNode* temp = curr->left;
                // need to check which side to go

                while(temp->right != NULL && temp->right != curr){
                    temp = temp->right;
                }

                if(temp->right == NULL){
                    // left subtree has not been traversed
                    temp->right = curr;
                    curr = curr->left;
                }
                else{
                    // left subtree has been traversed so temp->right = curr
                    temp->right = NULL;
                    ans.push_back(curr->val);
                    curr = curr->right;
                }
            }
        }

        return ans;
    }
};

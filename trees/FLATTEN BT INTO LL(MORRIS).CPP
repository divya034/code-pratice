    void flatten(TreeNode* root) {
        if(root == nullptr) return;
        TreeNode* curr = root;

        while(curr != NULL){
            if(curr->left != NULL){
                TreeNode* prev = curr->left;
                 cout<<prev->val; 

                while(prev->right){
                    prev = prev->right;
                }

                prev->right = curr->right;
                curr->right = curr->left;
                // important MISTAKE
                curr->left = nullptr;
            }

            curr = curr->right;
        }
    }
};

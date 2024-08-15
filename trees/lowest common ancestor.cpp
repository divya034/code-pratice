class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL){
            return NULL;
        }

        if(root->val == p->val){
            return root;
        }

        if(root->val == q->val){
            return root;
        }

        TreeNode* l = lowestCommonAncestor(root->left, p, q);
        TreeNode* r = lowestCommonAncestor(root->right, p, q);

        if(l == NULL && r == NULL){
            return NULL;
        }

        else if(l == NULL && r != nullptr){
            return r;
        }

        else if(l != nullptr && r == nullptr){
            return l;
        }
        else if(l!= nullptr && r != nullptr){
            return root;
        }

        return nullptr;
    }
};

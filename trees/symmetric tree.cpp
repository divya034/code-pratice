class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q){
        if(p == NULL && q == NULL){
            return true;
        }
        
        if(p == NULL || q == NULL){
            return false;
        }

        if(p->val != q->val){
            return false;
        }

        bool l = isSameTree(p->left, q->right);
        bool r = isSameTree(p->right, q->left);
        return l && r;
    }

    bool isSymmetric(TreeNode* root) {
        return isSameTree(root->left, root->right);
    }
};

O(N) AND OPTIMIZED APPROACH


TC O(N)
SPACE O(H)
  class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL)
        return nullptr;

        if(root == p){
            return p;
        }

        if(root == q){
            return q;
        }

        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);

        if(left == NULL && right == NULL){
            return NULL;
        }

        if(left != NULL && right == NULL){
            return left;
        }

        if(left == NULL && right != NULL){
            return right;
        }

        if(left != NULL && right != NULL){
            return root;
        }

        return root;
    }
};


OPTIMIZED:
 worst case (e.g., a skewed tree), the height H can be O(N)
In the best case (e.g., a perfectly balanced BST), the height H is O(log N), where N is the number
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL)
        return nullptr;

        if(root == p){
            return p;
        }

        if(root == q){
            return q;
        }

        if(p->val > root->val && q->val > root->val){
           return lowestCommonAncestor(root->right, p, q);
        }

        if(p->val < root->val && q->val < root->val){
           return lowestCommonAncestor(root->left, p, q);
        }

        if(p->val < root->val && q->val > root->val ||
              p->val > root->val && q->val < root->val){
              
              return root;
        }


        return root;
    }
};

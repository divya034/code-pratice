Time Complexity: O(N), where N is the number of nodes in the tree. Each node is visited exactly once.
Space Complexity: O(H), where H is the height of the tree, corresponding to the depth of the recursion stack.

class Solution {
public:
    bool checkValid(TreeNode* root, long mini, long maxi){
        if(root == NULL){
            return true;
        }

        bool left = checkValid(root->left, mini, root->val);
        bool right = checkValid(root->right, root->val, maxi);
        bool node = true;

        if(root->val < maxi && root->val > mini){
           node = true;
        }
        else{
            node = false;
        }

        return left && right && node;
    }
    bool isValidBST(TreeNode* root) {
        long minRange = LONG_MIN;
        long maxRange = LONG_MAX;

        return checkValid(root, minRange, maxRange);
    }
};

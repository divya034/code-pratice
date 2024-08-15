NO BACKTRACK:

class Solution {
public:
    bool isSumPresent(TreeNode* root, int target, int curr) {
        if (root == nullptr) {
            return false; // No path in an empty subtree
        }

        curr += root->val;

        // Check if we've reached a leaf node and if the current sum equals the target
        if (root->left == nullptr && root->right == nullptr) {
            return curr == target;
        }

        // Recur for left and right subtrees with the updated sum
        bool l = isSumPresent(root->left, target, curr);
        bool r = isSumPresent(root->right, target, curr);

        return l || r;
    }

    bool hasPathSum(TreeNode* root, int targetSum) {
        if (root == nullptr) {
            return false; // An empty tree does not have any path, so return false
        }
        return isSumPresent(root, targetSum, 0);
    }
};



BACKTRACKK

class Solution {
public:

    bool isSumPresent(TreeNode* root, int target, int &curr){
        if(root == nullptr){
            return false;
        }

        curr += root->val;
      // MISTAKE DIDNT CHECK CONDITION HERE
// WE NEED CURR NODES VAL TO BACKTRACK
        if(root->left == nullptr && root->right == nullptr){
            if(curr == target){
                return true;
            }
            else{
                curr = curr - root->val;
                return false;
            }
        }
        bool l = isSumPresent(root->left, target, curr);
        bool r = isSumPresent(root->right, target, curr);

        curr = curr - root->val;

        return l || r;
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        int currSum = 0;

        return isSumPresent(root, targetSum, currSum);
    }
};

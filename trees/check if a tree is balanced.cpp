

O(N)
class Solution {
public:
    // Helper function to check balance and compute height
    int checkBalance(TreeNode* root) {
        if (root == NULL) {
            return 0; // Height of an empty tree is 0
        }

        int leftHeight = checkBalance(root->left);
        if (leftHeight == -1) return -1; // Tree is unbalanced

        int rightHeight = checkBalance(root->right);
        if (rightHeight == -1) return -1; // Tree is unbalanced

        if (abs(leftHeight - rightHeight) > 1) {
            return -1; // Tree is unbalanced
        }

        return max(leftHeight, rightHeight) + 1; // Return height
    }

    bool isBalanced(TreeNode* root) {
        return checkBalance(root) != -1;
    }
};


O(N2)
class Solution {
public:
    int getHeight(TreeNode* root){
        if(root == NULL){
            return 0;
        }

        int lh = getHeight(root->left);
        int rh = getHeight(root->right);


        int ans = max(lh, rh) + 1;

        return ans;
    }
    bool isBalanced(TreeNode* root) {
    //    MISTAKE WROTE IF ROOT->LEFT == NULL AND ROOT->RIGHT == null RETURN TRUE BUT WE NEED TO CALCULATE THE HEIGHT
        if(root == NULL){
            return true;
        }
         
        int left = getHeight(root->left);
        int right = getHeight(root->right); 

        bool ans = abs(left-right) > 1 ? false : true;


// MISTAKE DIDNT WRITE CONSITION FOR ROOT-<EFT AND ROOT->>RIGHT
        // return (ans && isBalanced(root->left) && isBalanced(root->right));

        return ans;
        
    }
};

//         1
//        / \
//       2   2
//      /     \
//     3       3
//    /         \
//   4           4
// at 2 left height is 2
// and right height is 0
// UNLANACLED EVEN THO ROOT IS BALANCED

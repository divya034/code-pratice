tc:
o(logn) worsest case o(n)
sc: recur stack o(n)

or: with global variable
class Solution {
public:
    int sum = 0;
    int rangeSumBST(TreeNode* root, int low, int high) {
        if(root == nullptr) return 0;
        
        if(root->val > high){
            rangeSumBST(root->left, low, high);
        }
        else if(root->val < low){
            rangeSumBST(root->right, low, high);
        }
        else{
            sum = sum + root->val;
            rangeSumBST(root->left, low, high);
            rangeSumBST(root->right, low, high);
        }

        return sum;
    }
};

or:

class Solution {
public:

    int rangeSumBST(TreeNode* root, int low, int high) {
        if(root == nullptr) return 0;
        int sum = 0;

        if(root->val > high){
            sum += rangeSumBST(root->left, low, high);
        }
        else if(root->val < low){
            sum += rangeSumBST(root->right, low, high);
        }
        else{
            sum = sum + root->val;
            sum += rangeSumBST(root->left, low, high);
            sum += rangeSumBST(root->right, low, high);
        }

        return sum;
    }
};

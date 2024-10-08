O(N)
class Solution {
public:
    int height(TreeNode* root, int &maxi){
        if(root == NULL){
            return 0;
        }

        int lh = height(root->left, maxi);
        int rh = height(root->right, maxi);

        maxi = max(maxi, lh+rh);

        return max(lh,rh) + 1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int maxi = INT_MIN;

        height(root, maxi);

        return maxi;
    }
};



O(n2)

class Solution {
public:
    int height(TreeNode* root){
        if(root == NULL){
            return 0;
        }

        int lh = height(root->left);
        int rh = height(root->right);

        return max(lh,rh) + 1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if(root == NULL){
            return 0;
        }

        int lh = height(root->left);
        int rh = height(root->right);

        int totaledges = lh + rh;

        int leftd = diameterOfBinaryTree(root->left);
        int rightd = diameterOfBinaryTree(root->right);

        int maxi = max(totaledges, max(leftd,rightd));

        return maxi;

    }
};

TC:
O(N), where N is the total number of nodes in the tree.

SC:
In the best case (balanced BST), this is O(log N).
In the worst case (skewed BST), this is O(N).
class Solution {
public:
    void findSmallest(TreeNode* root, int &c, int k, int &ans){
        if(root == NULL){
            return;
        }

        findSmallest(root->left, c,k, ans);
        
        c++;
        if(c == k){
            ans = root->val;
        }

        findSmallest(root->right, c, k, ans);
    }
    int kthSmallest(TreeNode* root, int k) {
        int ans = 0;
        int count = 0;
        findSmallest(root, count, k, ans);

        return ans;
    }
};

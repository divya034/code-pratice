O(n)Time Complexity (TC): O(N), where N is the number of elements in the array.
Space Complexity (SC): O(log N) due to the depth of the recursion stack.

class Solution {
public:
    TreeNode* constructBinaryTree(vector<int> nums, int s, int e){
        // if s > e = out of bound
        if(s > e){
            return NULL;
        }

        int mid = s + (e-s)/2;
        int element = nums[mid];

        // Create node for the mid index
        TreeNode* node = new TreeNode(element);

        // construct left and right subtrees using recursion
        node->left = constructBinaryTree(nums, s, mid - 1);
        node->right = constructBinaryTree(nums, mid + 1, e);

        return node;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int s = 0;
        int e = nums.size() - 1;
        TreeNode* root = constructBinaryTree(nums, s, e);

        return root;
    }
};

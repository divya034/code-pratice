Time Complexity: O(N), where N is the number of nodes in the BST, since each node is processed exactly once.
Space Complexity: O(H), where H is the height of the BST, due to the recursion stack. In the worst case, this could be O(N) for a skewed tree,
ONLY USING MAX BOUND
class Solution {
public:
    TreeNode* build(vector<int> preorder, int &index, int maxi){
        if(index >= preorder.size() || preorder[index] > maxi){
            return NULL;
        }
        
        int element = preorder[index]; index++;
        TreeNode* node = new TreeNode(element);
        node->left = build(preorder, index, element);
        node->right = build(preorder, index, maxi);

        return node;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int index = 0;

        return build(preorder, index, INT_MAX);
    }
};

Time Complexity: O(N), where N is the number of nodes in the BST, since each node is processed exactly once.
Space Complexity: O(H), where H is the height of the BST, due to the recursion stack. In the worst case, this could be O(N) for a skewed tree,
class Solution {
public:
    TreeNode* build(vector<int> preorder, int &index, int mini, int maxi){
        if(index >= preorder.size() || preorder[index] < mini || preorder[index] > maxi){
            return NULL;
        }
        
        int element = preorder[index];
        index++;

        TreeNode* node = new TreeNode(element);

        node->left = build(preorder, index, mini, element);
        node->right = build(preorder, index, element, maxi);

        return node;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int index = 0;

        return build(preorder, index, INT_MIN, INT_MAX);
    }
};

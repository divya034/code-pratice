Time Complexity:

findinorder function:
Inorder Traversal: The function findinorder traverses the entire tree in an inorder fashion, which takesO(N) time where 
N is the number of nodes in the tree.
build function:
constructs a balanced BST from the inorder traversal. Since the function processes each element of the inorder list exactly once, the time complexity is also 
O(N).
Overal =o(n) + o(n)

Space Complexity:

The findinorder function stores the inorder traversal in a vector, which takes O(N) space.
Recursive Stack Space:
Both the findinorder and build functions use recursion. The depth of the recursion is bounded by the height of the tree.
worst-case space complexity for the recursion stack would be o(n)

Overall Space Complexity:
total space complexity is O(N) for storing the inorder traversal plus O(logN) for the recursion stack in the balanced case.


class Solution {
public:
    void findinorder(vector<TreeNode*> &inorder, TreeNode* root){
        if(root == 0){
            return;
        }

        findinorder(inorder, root->left);
        inorder.push_back(root);
        findinorder(inorder, root->right);
    }

    TreeNode* build(vector<TreeNode*> inorder, int s, int e){
        if(s > e){
            return nullptr;
        }
        int middle = (s + e) / 2;
        TreeNode* head = inorder[middle];

        head->left = build(inorder, s, middle - 1);
        head->right = build(inorder, middle + 1, e);

        return head;

    }
    TreeNode* balanceBST(TreeNode* root) {
        // find inorder
        // take middle element
        // build a tree
        vector<TreeNode*> inorder;
        findinorder(inorder, root);

        return build(inorder, 0, inorder.size() - 1);
    }
};

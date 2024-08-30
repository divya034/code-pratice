RECURSIVE:
Time Complexity: O(H), where H is the height of the tree. This is O(log N) for a balanced tree and O(N) for a skewed tree
Space Complexity: O(H) due to the recursion stack. This is O(log N) for a balanced tree and O(N) for a skewed tree.
class Solution {
public:
    void insertNode(TreeNode* &head, int val){
        if(head == NULL){
            head = new TreeNode(val);
            return;
        }
        
        if(head->val > val){
            insertNode(head->left, val);
        }
        else{
            insertNode(head->right, val);
        }

        return;

    }
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(root == nullptr) return new TreeNode(val);

        insertNode(root, val);
        return root;
    }
};


Best Case: O(log N) 
Space Complexity: O(1)
class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(root == nullptr) return new TreeNode(val);

        TreeNode* curr = root;

        while(true){
            if(curr->val > val){
                if(curr->left != NULL)
                    curr = curr->left;
                else{
                    curr->left = new TreeNode(val);
                    break;
                }
            }
            else{
                if(curr->right != NULL){
                    curr = curr->right;
                }
                else{
                    curr->right = new TreeNode(val);
                    break;
                }
            }
        }

        return root;
    }
};

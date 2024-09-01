RECURSIVE:
Time Complexity: O(H), where H is the height of the tree. This is O(log N) for a balanced tree and O(N) for a skewed tree
Space Complexity: O(H) due to the recursion stack. This is O(log N) for a balanced tree and O(N) for a skewed tree.
2 same code with or without &:
class Solution {
public:
    // Function to insert a node into the BST
    TreeNode* insertNode(TreeNode* head, int val) {
        if(head == nullptr) {
            return new TreeNode(val);
        }
        
        // Recursive insertion
        if(val < head->val) {
            head->left = insertNode(head->left, val);
        } else {
            head->right = insertNode(head->right, val);
        }
        
        return head; // Return the (potentially modified) head
    }
    
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        // If the root is null, create a new node with the value
        if(root == nullptr) return new TreeNode(val);
        
        // Insert the node into the BST
        return insertNode(root, val);
    }
};


or:


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

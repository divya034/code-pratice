
NOT WORKING
class Solution
{
public:
    // Helper function to find the maximum value node in a subtree
    Node* findMax(Node* node) {
        while (node && node->right) {
            node = node->right;
        }
        return node;
    }
    
    // Helper function to find the minimum value node in a subtree
    Node* findMin(Node* node) {
        while (node && node->left) {
            node = node->left;
        }
        return node;
    }
    
    void findPreSuc(Node* root, Node*& pre, Node*& suc, int key)
    {  
       if(root == NULL) {
           return;
       }
       
       if(root->key == key) {
           // Find the maximum in the left subtree for predecessor
           if(root->left) {
               pre = findMax(root->left);
           } else {
               pre = NULL;
           }
           
           // Find the minimum in the right subtree for successor
           if(root->right) {
               suc = findMin(root->right);
           } else {
               suc = NULL;
           }
       }
       else if(key < root->key) {
           // Current node is a potential successor
           suc = root;
           // Search in the left subtree
           findPreSuc(root->left, pre, suc, key);
       }
       else {
           // Current node is a potential predecessor
           pre = root;
           // Search in the right subtree
           findPreSuc(root->right, pre, suc, key);
       }
    }
};

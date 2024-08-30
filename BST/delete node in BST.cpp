class Solution {
public:
    void del(TreeNode* &root, int key){
        if(root == NULL){
            return;
        }

        if(root->val == key){
            root = helper(root);
            return;
        }

        if(key > root->val){
            // key is greater, so go on right subtree
            if(root->right != NULL && root->right->val == key){
                root->right = helper(root->right);
            }
            else{
                del(root->right, key);
            }
        }
        else{ 
            // key is smaller, so go on left subtree
            if(root->left != NULL && root->left->val == key){
               root->left = helper(root->left);
            }
            else{
                del(root->left, key);
            }
        }
    }

    TreeNode* helper(TreeNode* &root){
        if(root->right == nullptr && root->left == nullptr){
            delete root;
            return NULL;
        }
        else if(root->right == nullptr && root->left != nullptr){
            TreeNode* nextNode = root->left;
            delete root;
            return nextNode;
        }
        else if(root->left == nullptr && root->right != nullptr){
            TreeNode* nextNode = root->right;
            delete root;
            return nextNode;
        }
        else{
            // both sides are not null
            TreeNode* rightSubtree = root->right;
            TreeNode* itr = root->left;
            while(itr->right){
                itr = itr->right;
            }
            // connect the rightmost child in left subtree to right subtree
            itr->right = rightSubtree;

            return root->left;
        }

    return root;
        
    }

    TreeNode* deleteNode(TreeNode* root, int key) {

        del(root, key);

        return root;
    }
};

class BSTIterator {
public:
    stack<TreeNode*> s;
    void pushall(TreeNode* root){
        while(root){
           s.push(root);
           root = root->left;
        }
    }
    BSTIterator(TreeNode* root) {
        pushall(root);
    }
    
    int next() {
        TreeNode* tmp = s.top();
        s.pop();
        if(tmp->right){
            pushall(tmp->right);
        }

        return tmp->val;
    }
    
    bool hasNext() {
        if(!s.empty()){
            return true;
        }

        return false;
    }
};

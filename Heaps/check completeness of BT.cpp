class Solution {
public:
    bool isCompleteTree(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        bool foundNull = false;

        while(!q.empty()){
             TreeNode* frontele = q.front();
             q.pop();

             if(frontele == NULL){
                foundNull = true;
             }

             if(frontele != NULL && foundNull == true){
                return false;
             }
             
             if(frontele != NULL){
             q.push(frontele->left);
             q.push(frontele->right);
             }
        }

        return true;
    }
};

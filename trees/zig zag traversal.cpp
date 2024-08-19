O(n)
o(n)

class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        queue<TreeNode*> q;
        vector<vector<int>> ans;
        if(root == NULL){
            return ans;
        }

        q.push(root);
        bool flag = true; 
        // right = left

        while(!q.empty()){
            int n = q.size();
            vector<int>level;
            for(int i = 0; i<n; i++){

                TreeNode* node = q.front();
                q.pop();

                if(node->left){
                    q.push(node->left);
                }
            
                if(node->right){
                    q.push(node->right);
                }

                level.push_back(node->val);

            }

            if(flag == false){
                reverse(level.begin(), level.end());
                ans.push_back(level);
            }
            else{
                ans.push_back(level);
            }

            flag = !flag;
            
        }

        return ans;
    }
};


using dequeue instead of vector
o(n)
o(n)
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        queue<TreeNode*> q;
        vector<vector<int>> ans;
        if(root == NULL){
            return ans;
        }

        q.push(root);
        bool flag = true; 
        // right = left

        while(!q.empty()){
            int n = q.size();
            vector<int>level;
            for(int i = 0; i<n; i++){

                TreeNode* node = q.front();
                q.pop();

                if(node->left){
                    q.push(node->left);
                }
            
                if(node->right){
                    q.push(node->right);
                }

                level.push_back(node->val);

            }

            if(flag == false){
                reverse(level.begin(), level.end());
                ans.push_back(level);
            }
            else{
                ans.push_back(level);
            }

            flag = !flag;
            
        }

        return ans;
    }
};

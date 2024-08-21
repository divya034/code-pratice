class Solution {
public:
   void solve(TreeNode* root, int col, int row, int &mini, int &maxi,  unordered_map<int, vector<pair<int, int>>> &m){
        if(root == NULL) return;
    
        // if(m.find(col) != m.end() && root->val < m[col][m[col].size() - i + 1])
        m[col].push_back({row, root->val});

        mini = min(mini, col);
        maxi = max(maxi, col);
        solve(root->left, col - 1, row + 1, mini, maxi, m);
        solve(root->right, col + 1, row + 1, mini, maxi, m);
   }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        int mini = INT_MAX;
        int maxi = INT_MIN;
        unordered_map<int, vector<pair<int,int>>> m;
        int col = 0;
        int row = 0;
        solve(root, col, row, mini, maxi,m);

        vector<vector<int>> ans;

        for(int i = mini; i<= maxi; i++){
            vector<pair<int,int>> temp = m[i];
            sort(temp.begin(), temp.end());

            vector<int> column;
            for(auto p : temp){
                column.push_back(p.second); // Push back the node values in the sorted order
            }
            ans.push_back(column);
        }

        return ans;
    }
};

class Solution {
  public:
      void solve(Node* root, vector<int> &ans, int dist, int currlevel,
    unordered_map<int, pair<int,int>>&m, int &mini, int &maxi){
        if(root == nullptr){
            return;
        }
        
        // we need conditions because
        if(m.find(dist) == m.end() || currlevel >= m[dist].second ){
            mini = min(mini, dist);
            maxi = max(maxi, dist);
            
            m[dist] = {root->data, currlevel};
        }
        
        solve(root->left, ans, dist-1, currlevel +1, m, mini, maxi);
        solve(root->right, ans, dist+1, currlevel +1, m, mini, maxi);
    }
    vector <int> bottomView(Node *root) {
       vector<int> ans;
        
        if(root == NULL){
            return ans;
        }
        
        int dist = 0;
        unordered_map<int, pair<int,int>> m;
        // dist, data and level
        
        int mini = INT_MAX;
        int maxi = INT_MIN;
        
        solve(root, ans, dist, 0, m, mini, maxi);
        
        for(int i = mini; i<= maxi; i++){
            ans.push_back(m[i].first);
        }
        
        return ans;
    }
};

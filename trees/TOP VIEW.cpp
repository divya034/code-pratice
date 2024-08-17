class Solution
{
    public:
    //Function to return a list of nodes visible from the top view 
    //from left to right in Binary Tree.
    void solve(Node* root, vector<int> &ans, int dist, int currlevel,
    unordered_map<int, pair<int,int>>&m, int &mini, int &maxi){
        if(root == nullptr){
            return;
        }
        
        if(m.find(dist) == m.end() || currlevel < m[dist].second ){
            mini = min(mini, dist);
            maxi = max(maxi, dist);
            
            m[dist] = {root->data, currlevel};
        }
        
        solve(root->left, ans, dist-1, currlevel +1, m, mini, maxi);
        solve(root->right, ans, dist+1, currlevel +1, m, mini, maxi);
    }
    vector<int> topView(Node *root)
    {
        vector<int> ans;
        
        if(root == NULL){
            return ans;
        }
        
        int dist = 0;
        unordered_map<int, pair<int,int>> m;
        // distance, data and level
        
        int mini = INT_MAX;
        int maxi = INT_MIN;
        
        solve(root, ans, dist, 0, m, mini, maxi);
        // mistake didnt write m[i].first
        for(int i = mini; i<= maxi; i++){
            ans.push_back(m[i].first);
        }
        
        return ans;
    }

};

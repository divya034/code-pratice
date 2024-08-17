BABBAR CODE:
class Solution
{
    public:
    //Function to return a list of nodes visible from the top view 
    //from left to right in Binary Tree.
    vector<int> topView(Node *root)
    {
         vector<int> ans;
         if(root == nullptr){
             return ans;
         }
         
        queue<pair<Node*, int>>q;
        
        q.push({root,0});
        int mini = INT_MAX;
        int maxi = INT_MIN;
        
        unordered_map<int, int> m;
        // dist to root->data
        
        while(!q.empty()){
            pair<Node*, int> p = q.front();
            q.pop();
            
            Node* frontnode = p.first;
            int hd = p.second;
            
            if(m.find(hd) == m.end()){
                m[hd] = frontnode->data;
                mini = min(mini, hd);
                maxi = max(maxi, hd);
            }
            
            if(frontnode->left){
                q.push({frontnode->left, hd-1});
            }
            
            if(frontnode->right){
                q.push({frontnode->right, hd+1});
            }
        }
        
        
        for(int i = mini; i<=maxi; i++){
            ans.push_back(m[i]);
        }
        
        return ans;
    }

};


MY MAP CODE:
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

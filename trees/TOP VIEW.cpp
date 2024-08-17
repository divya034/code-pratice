babbar code:
class Solution {
  public:
    vector <int> bottomView(Node *root) {
       vector<int> ans;
       
       queue<pair<Node*, int>> q;
    //   Node and hd
       q.push({root,0});
       unordered_map<int, int> m;
    //   hd to root->data
    
        int mini = INT_MAX;
        int maxi = INT_MIN;
    
        while(!q.empty()){
            pair<Node*, int> p = q.front();
            q.pop();
            
            Node* frontnode = p.first;
            int hd = p.second;
            
            m[hd] = frontnode->data;
            mini = min(mini, hd);
            maxi = max(maxi, hd);
            
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


my map solution:


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

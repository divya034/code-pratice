class Solution {
  public:
    vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
        vector<int> ans;
        unordered_map<int,int> m;
        
        for(int i = 0; i<V; i++){
            if(adj[i].size() == 0){
                ans.push_back(i);
                m[i] = 1;
            }
        }
        
        for(int i = 0; i<V; i++){
            if(adj[i].size() == 1 && m.find(adj[i][0]) != m.end()){
                ans.push_back(i);
            }
        }
        
        sort(ans.begin(), ans.end());
        
        return ans;
        
        
    }
};

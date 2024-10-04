class Solution {
  public:
    
    void dfs(int start, vector<int> &ans, vector<int> &vis, vector<int> adj[]){
        int vis[start] = 1;
        ans.push_back(start);
        
        for(auto it: adj[node]){
            if(!vis[it]){
                dfs(it, ans, vis, adj);
            }
        }
    }
    // Function to return a list containing the DFS traversal of the graph.
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        vector<int> vis(V, 0);
        
        int start = 0;
        
        vector<int> ans;
        
        dfs(start, ans, vis, adj);
        
        return ans;
    } 
};

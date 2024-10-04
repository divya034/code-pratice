class Solution {
  public:
    void dfs(int node, vector<int>& vis, vector<int> adjlist[]){
        vis[node] = 1;
        
        for(auto it: adjlist[node]){
            if(!vis[it]){
                dfs(it, vis, adjlist);
            }
        }
        
    }
    int numProvinces(vector<vector<int>> adj, int V) {
        vector<int> adjlist[V];
        
        for(int i = 0; i<V; i++){
            for(int j = 0; j<V; j++){
                if(adj[i][j] == 1){
                    adjlist[i].push_back(j);
                    adjlist[j].push_back(i);
                }
            }
        }
        
        vector<int> vis(V, 0);
        int cnt = 0;
        
        for(int i = 0; i<V; i++){
            if(!vis[i]){
                cnt++;
                dfs(i, vis, adjlist);
            }
        }
        
        return cnt;
    }
};

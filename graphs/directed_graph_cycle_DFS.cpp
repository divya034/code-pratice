
TC: o(n+e)
sc:
path = o(v)
vis = o(v)
recur stack = o(v) 


class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool dfs(vector<int> adj[], vector<int> &vis, vector<int> &path, int i){
        vis[i] = 1;
        path[i] = 1;
        
        for(auto nbr : adj[i]){
            if(vis[nbr] == 1 && path[nbr] == 1){
                return true;
            }
            else if(vis[nbr] == 0){
                
               if(dfs(adj, vis, path, nbr) == true){
                    return true;
                }
            }
        }
        
        path[i] = 0;
        
        return false;
    }
    bool isCyclic(int V, vector<int> adj[]) {
        vector<int> vis(V, 0);
        vector<int> path(V, 0);
        
        // need to make sure if all are false so we place
        // false at the end
        for(int i = 0; i<V; i++){
            if(!vis[i]){
                if(dfs(adj, vis, path, i) == true){
                    return true;
                }
            }
        }
        
        return false;
    }
};

DFS: 
SC: O(V+E)---> ADJ list
vis, pathsum ---o(v)
  
TC: O(V+E)

All the nodes, that in further path dont get a cycle gets unmarked as path = 0.
All the nodes which are part of a cycle or lead to a cycle remain in path = 1.
everything without/no leading to a cycle gets unvisited after dfs ends

class Solution {
  public:
    bool findcycle(int node, vector<int> &vis, vector<int> &pathsum,
    vector<int> &safe, vector<int> adj[]){
        vis[node] = 1;
        pathsum[node] = 1;
        
        for(auto i: adj[node]){
            if(!vis[i]){
                if(findcycle(i, vis, pathsum, safe, adj))
                    return true;
            }
            else if(pathsum[i] == 1){
                return true;
            }
        }
        
        pathsum[node] = 0;
        return false;
    }
    vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
        
        vector<int> safe;
        vector<int> vis(V, 0);
        vector<int> pathsum(V, 0);
        
        for(int i = 0; i<V; i++){
            if(!vis[i]){
                findcycle(i, vis, pathsum, safe, adj);
            }
        }
        
        // as soon as we find a cycle we return
        // so we wont explore the ones that are
        // not part of the cycle
        // everything without a cycle gets unvisited after dfs ends
        for(int i = 0; i<V; i++){
            if(!pathsum[i]){
                safe.push_back(i);
            }
        }
        
        
        sort(safe.begin(), safe.end());
        return safe;
    }
};


small change with check vector<int> STRIVER SOLUTION:
class Solution {
  public:
    bool dfs(int node, vector<int> &vis, vector<int> &path,
        vector<int> &check, vector<int> adj[]){
            vis[node] = 1;
            path[node] = 1;
            
            for(auto i: adj[node]){
                if(!vis[i]){
                    if(dfs(i, vis, path, check, adj)){
                        return true;
                    }
                }
                else if(path[i] == 1){
                    return true;
                }
            }
            
            path[node] = 0;
            check[node] = 1;
            return false;
        }
    vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
        vector<int> vis(V, 0);
        
        vector<int> path(V, 0);
        vector<int> check(V, 0);
        
        for(int i = 0; i<V; i++){
            dfs(i, vis, path, check, adj);
        }
        
        vector<int> ans;
        for(int i = 0; i<V;i++){
            if(check[i] == 1) ans.push_back(i);
        }
        
        return ans;
    }
};

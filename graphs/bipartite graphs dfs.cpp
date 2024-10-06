TC: we reach all nodes once
O(N + 2e) or V + 2e

SC:
recursion stack --- o(N)
  color vector --- o(n)
  adj list -----o(N + 2e)


class Solution {
private:
    bool dfs(vector<int>adj[], int col, vector<int>& color, int i){
        color[i] = col;
        
        for(auto nbr: adj[i]){
            if(color[nbr] == -1){
                if(dfs(adj, !col, color, nbr) == false){
                    return false;
                }
            }
            
            else if(color[nbr] == col){
                return false;
            }
        }
        
        return true;
    }
    
public:
	bool isBipartite(int V, vector<int>adj[]){
	    vector<int> color(V, -1);
	    
	    for(int i = 0; i<V; i++){
	        if(color[i] == -1){
	            if(dfs(adj, 0, color, i) == false){
	                return false;
	            }
	        }
	    }
	    
	    return true;
	}

};

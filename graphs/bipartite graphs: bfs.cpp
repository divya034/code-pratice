TC:
Trvaerse all nodes and degrees
N + 2E

SC:
color: O(V)
queue: o(v)
  

class Solution {
private:
    bool check(vector<int> adj[], vector<int> &color, int i){
        
        queue<int> q;
        q.push(i);
        color[i] = 0;
        
        while(!q.empty()){
            int node = q.front();
            q.pop();
            
            for(auto nbr: adj[node]){
                
                // q.push(nbr);
                
                if(color[nbr] == -1){
                    color[nbr] = !color[node];
                    q.push(nbr);
                }
                else if(color[nbr] == color[node]){
                    return false;
                }
            }
        }
        
        return true;
    }
    
public:
	bool isBipartite(int V, vector<int>adj[]){
	   
	   vector<int> color(V, -1);
	   //color with 0 and 1
	   
	   for(int i = 0; i<V; i++){
	       if(color[i] == -1){
	           if(check(adj, color, i) == false)
	                return false;
	       }
	   }
	   
	   return true;
	   
	   
	}

};

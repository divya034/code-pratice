TC: O(N + e)

SC: 
  queue --- <O(n)
  worst case^ as topo sort will never be N in case of cyclic directed graph;

  adj list---o(n+e)
  indegree ----o(n)



class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        vector<int> indegree(V, 0);
        
        for(int i = 0; i<V; i++){
            for(auto nbr: adj[i]){
                indegree[nbr]++;
                // i points to nbr
            }
        }
        
        
        queue<int> q;
        int c = 0;
        for(int i = 0; i<V; i++){
            if(indegree[i] == 0){
                q.push(i);
                c++;
            }
        }
        
        while(!q.empty()){
            int node = q.front();
            q.pop();
            
            for(auto nbr: adj[node]){
                indegree[nbr]--;
                
                if(indegree[nbr] == 0){
                    q.push(nbr);
                    c++;
                }
            }
        }
        
        return c != V;
    }
};

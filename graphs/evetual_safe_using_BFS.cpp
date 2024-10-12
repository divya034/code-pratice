TC: 
o(v+e)--> INDEGREE
o(v+e)--->bfs
o(v)--->push into indegree[] == 0

SC:
O(V+E)---> adjT
O(V+E)----> adj
O(V)---> INDEGREE vector
O(v)---->safe vector


class Solution {
  public:
    vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
        vector<int> adjT[V];
        vector<int> indegree(V, 0);
        
        for(int i = 0; i<V; i++){
            for(auto j: adj[i]){
                adjT[j].push_back(i);
                indegree[i]++;
            }
        }
        
        queue<int> q;
        for(int i = 0; i<V; i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }
        
        vector<int> safe;
        while(!q.empty()){
            int topele = q.front();
            q.pop();
            
            safe.push_back(topele);
            
            for(auto i: adjT[topele]){
                indegree[i]--;
                if(indegree[i] == 0){
                    q.push(i);
                }
            }
        }
        
        sort(safe.begin(), safe.end());
        return safe;
    }
};

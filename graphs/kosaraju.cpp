TC: o(V+e) x 2 two dfs
reverse grapg o(v+e)

SC:
o(v) --> stack
o(v)---> vis
  o(V+e--->adjT


class Solution
{   private:
    void dfs(vector<vector<int>>&adj, int node, vector<int> &vis, stack<int>&st){
        vis[node] = 1;
        
        for(auto j: adj[node]){
            if(!vis[j]){
                dfs(adj, j, vis, st);
            }
        }
        
        st.push(node);
    }
    private:
    void dfsT(vector<vector<int>>&adj, int node, vector<int> &vis){
        vis[node] = 1;
        
        for(auto i: adj[node]){
            if(!vis[i]){
                dfsT(adj, i, vis);
            }
        }
    }
	public:
	//Function to find number of strongly connected components in the graph.
    int kosaraju(int V, vector<vector<int>>& adj)
    {
        // step 1: sort based on finishing time
        vector<int> vis(V, 0);
        stack<int> st;
        
        for(int i = 0; i<V; i++){
            if(!vis[i]){
                dfs(adj, i, vis, st);
            }
        }
        
        // step 2: reverse the graph
        vector<vector<int>> adjT(V);
        
        for(int i = 0; i<V; i++){
            vis[i] = 0;
            for(auto j: adj[i]){
                adjT[j].push_back(i);
            }
        }
        
        // step 3: perform DFS on reversed graph to get indivialy scc
        int scc = 0;
        // vector<int> visT(V, 0);
        while(!st.empty()){
            int node = st.top();
            st.pop();
    
            if(!vis[node]){
                dfsT(adjT, node, vis);
                scc++;
            }

        }
        return scc;
    }
};

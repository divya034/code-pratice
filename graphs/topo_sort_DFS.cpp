TC: O(N + e)
SC: 
  vis---o(n)
  stack(n)

class Solution
{
	public:
	void topo(vector<int> adj[], vector<int> &vis, stack<int> &s, int i){
	    vis[i] = 1;
	    
	    for(auto nbr: adj[i]){
	        if(vis[nbr] != 1){
	            topo(adj, vis, s, nbr);
	        }
	    }
	    
	    s.push(i);
	}
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    vector<int> vis(V, 0);
	    stack<int> st;
	    for(int i = 0; i<V; i++){
	        if(!vis[i]){
	            topo(adj, vis, st, i);
	        }
	    }
	    
	    vector<int> ans;
	    
	    while(!st.empty()){
	        int ele = st.top();
	        ans.push_back(ele);
	        st.pop();
	    }
	    
	   // reverse(ans.begin(), ans.end());
	    
	    return ans;
	}
};

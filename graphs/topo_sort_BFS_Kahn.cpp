TC: N + e
sc:
indegree --> o(N)
queue ---> o(n)
ans ---> o(n)


class Solution
{
	public:
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    vector<int> indegree(V, 0);
	    for(int i = 0; i<V; i++){
	        for(auto nbr: adj[i]){
	            indegree[nbr]++;
	        }
	    }
	    
	    queue<int> q;
	    vector<int> ans;
	    
	    for(int i = 0; i<V; i++){
	        if(indegree[i] == 0){
	            q.push(i);
	        }
	    }
	    
	    while(!q.empty()){
	        int node = q.front();
	        q.pop();
	        
	        ans.push_back(node);
	        
	        for(auto nbr: adj[node]){
	            indegree[nbr]--;
	            
	            if(indegree[nbr] == 0){
	                q.push(nbr);
	            }
	        }
	    }
	    
	    return ans;
	    
	}
};

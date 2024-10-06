TC: n+e
SC: queue---o(n)
  ans----o(n)
  


class Solution {
public:
	bool isPossible(int N,int P, vector<pair<int, int> >& pre) {
	    vector<int> adj[N];
	    
	    for(auto i : pre){
	        adj[i.first].push_back(i.second);
	    }
	    
	    vector<int> indegree(N, 0);
	    
	    for(int i = 0; i<N; i++){
	        for(auto nbr : adj[i]){
	            indegree[nbr]++;
	        }
	    }
	    
	    queue<int> q;
	    vector<int> ans;
	    
	    for(int i = 0; i<N; i++){
	        if(indegree[i] == 0){
	            ans.push_back(i);
	            q.push(i);
	        }
	    }
	    
	    while(!q.empty()){
	        int node = q.front();
	        q.pop();
	        
	        for(auto nbr: adj[node]){
	            indegree[nbr]--;
	            
	            if(indegree[nbr] == 0){
	                q.push(nbr);
	                ans.push_back(nbr);
	            }
	        }
	    }
	    
	    if(ans.size() == N){
	       // sort happened-->no cycle
	       return true;
	    }
	    else{
	        return false;
	    }
	    
	    
	}
};

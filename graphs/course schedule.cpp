TC: O(n + e)

sc:
ans---->o(n)
queue---->o(n)
adj----->(n+e)

class Solution
{
  public:
    vector<int> findOrder(int n, int m, vector<vector<int>> pre) 
    {
       vector<int> adj[n];
       
       for(auto i : pre){
           adj[i[1]].push_back(i[0]);
       }
       
       vector<int> indegree(n,0);
       for(int i = 0; i<n; i++){
           for(auto nbr: adj[i]){
               indegree[nbr]++;
           }
       }
       
       queue<int> q;
       vector<int> ans;
       
       for(int i = 0; i<n; i++){
           if(indegree[i] == 0){
               q.push(i);
               ans.push_back(i);
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
       
       if(ans.size() == n){
           return ans;
       }
       else{
           return {};
       }
    }
};

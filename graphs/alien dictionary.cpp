When order is not possible??
DAG:
1. when there is no direction:
str1: abcd
str2: abc
we wont find any adj list because a b and c are matching,
there is no direction for d

shorter string abc should be before abcd
In this case, the first three characters 'a', 'b', and 'c' are the same in both words, but str1 is longer than str2. 
According to lexicographical order rules, a shorter word should always come before its longer prefix. 
But in this case, str2 (shorter) comes after str1 (longer), violating the rule.
Conclusion: Whenever a shorter word appears after its longer prefix in the dictionary, the alien language order is not valid. This results in no possible topological sorting.

  
2. when there is a cyclic dependency:

abc
bdf
adc

a->b
b->a
  Whenever there is a cyclic dependency in the graph of character relationships, it is impossible to determine a valid order for the characters.

CODE:
  
Striver code's, i HAD similar approach but build adj WITHOUT using int values, I am using strings as node
  TC: (number words x (min length of two words)) + 
  BFS: TOPOSORT --> O(N + E)
  SC: 
  extra space used: 
toposort---> O(N) n is number of characters
ans = O(N)
  
class Solution {
  public:
    vector<int> bfs(int V, vector<int> adj[]){
        vector<int> indegree(V,0);
        queue<int> q;
        
        for(int i = 0; i<V; i++){
            for(auto j : adj[i]){
                indegree[j]++;
            }
        }
        
        for(int i = 0; i<V; i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }
        
        vector<int> toposort;
        while(!q.empty()){
            int top = q.front();
            toposort.push_back(top);
            q.pop();
            
            for(auto i: adj[top]){
                indegree[i]--;
                
                if(indegree[i] == 0){
                    q.push(i);
                }
            }
        }
        
        return toposort;
    }
    string findOrder(string dict[], int n, int k) {
        vector<int> adj[k];
        
        for(int i = 0; i < n-1; i++){
            string str1 = dict[i];
            string str2 = dict[i+1];
            
            int len = min(str1.size(), str2.size());
            
            for(int j = 0; j<len; j++){
                if(str1[j] != str2[j]){
                    adj[str1[j] - 'a'].push_back(str2[j] - 'a');
                    break;
                }
            }
        }
        

        vector<int> toposort = bfs(k, adj);

        string ans;

        for(auto i: toposort){
            char alphabet = i + 'a';
            ans = ans + alphabet;
        }
        
        
        return ans;
    }
};


my approach and chargpt code:
class Solution {
public:
    // DFS for topological sort
    void dfs(char node, unordered_map<char, bool> &vis, stack<char> &s, unordered_map<char, vector<char>> &adj) {
        vis[node] = true;
        
        // Visit all neighbors of the current node
        for (auto neighbor : adj[node]) {
            if (!vis[neighbor]) {
                dfs(neighbor, vis, s, adj);
            }
        }
        
        // Push the character to stack after visiting all its neighbors
        s.push(node);
    }
    
    string findOrder(string dict[], int n, int k) {
        unordered_map<char, vector<char>> adj;  // Graph adjacency list
        
        // Build the graph by comparing adjacent words
        for (int i = 0; i < n - 1; i++) {
            string word1 = dict[i];
            string word2 = dict[i + 1];
            int len = min(word1.size(), word2.size());
            
            // Find the first differing character and build the adjacency list
            for (int j = 0; j < len; j++) {
                if (word1[j] != word2[j]) {
                    adj[word1[j]].push_back(word2[j]);  // Directly use characters
                    break;  // Only the first mismatch matters
                }
            }
        }
        
        // Topological sort using DFS
        unordered_map<char, bool> vis;  // To track visited nodes
        stack<char> s;  // To store the topological sort
        
        // Perform DFS on each character in the adjacency list
        for (auto it : adj) {
            if (!vis[it.first]) {
                dfs(it.first, vis, s, adj);
            }
        }
        
        // Collect the topologically sorted order from the stack
        string toposort;
        while (!s.empty()) {
            toposort += s.top();
            s.pop();
        }
        
        return toposort;
    }
};




my code:
class Solution {
  public:
    // topological sort using DFS
    void dfs(int node, vector<string> &vis, stack<char> &s, 
        vector<char> adj[K]){
        vis[node] = 1;
        
        for(auto i: adj[node]){
            if(!vis[i]){
                dfs(i, vis, s, adj);
            }
        }
        
        s.push(node);
        // if dictionary doesn't had char 'x', stack will anyway add it
        // as we are looping over N ---> number of chars from normal dict
        
    }
    string findOrder(string dict[], int n, int k) {
        // k is the- number of v
        vector<char> adj[K];
        
        // multiple words in the dictionary
        if(dict.size() > 1){
            int i = 0; 
            int j = i+1;
            while(j < dict.size()){
                
                while(i < j){
                    int it1 = dict[i];
                    int it2 = dict[j];
                    while(it1 < i.size() && it2 < j.size()){
                        if(it1 != it2){
                            if(adj[it] != {})
                            adj[it1].push_back(it2);
                            break;
                        }
                        else{
                            it1++;
                            it2++;
                        }
                    }
                }
                
                i++;
                j++;
            }
        }
        
        // there is only one word in the dictionary
        else{
            // all letters of the word are same
            bool allaresame = 1;
            string word = dict[0];
            for(int i = 0; i<word.size()-1; i++){
                if(word[i] != word[i+1]){
                    adj[i].push_back(i+1);
                    allaresame = 0;
                }
                else{
                    continue;
                }
            }
            
            if(allaresame == 1){
                return {word[0]};
            }
        }
        
        // get topo sort 
        string toposort;
        vector<int> vis(n, 0);
        stack<char> s;
        
        for(int i = 0; i<n; i++){
            if(!vis[i]){
               dfs(i, vis, s, adj); 
            }
        }
        
        // construct ans using topo sort done
        while(!s.empty()){
            int topele = s.top();
            toposort = toposort + topele;
        }
        
        return toposort;
    }
};

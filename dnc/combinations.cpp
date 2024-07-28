class Solution {
public:

void solve(vector<vector<int>> &ans, vector<int> &curr, int n, int k, int i){
    // mistake did not write & FOR ANs and curr
    // here we are changing curr value out of function call so it needs to be remebered

    if(k == 0){
        ans.push_back(curr);
        return;
    }

    for(int j = i; j<=n; j++){
        curr.push_back(j);
        // mistake wrote i+1 instead of j+1
        solve(ans,curr, n, k-1, j+1);
        curr.pop_back();
    }
}

    vector<vector<int>> combine(int n, int k) {
        
        vector<vector<int>> ans;
        vector<int> curr;
        solve(ans, curr, n, k, 1);

        return ans;
    }
};

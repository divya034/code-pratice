class Solution {
public:
   void solve(vector<string>& ans, string out, int open, int close, int n){
    if(open + close == 2*n){
        ans.push_back(out);
        return;
    }

    if(open < n){
// here out will be backtracked when the function call comes back
        solve(ans, out + '(', open+1, close, n);
    }
    if(close < open){
        solve(ans, out + ')', open, close+1, n);
    }
   }
    vector<string> generateParenthesis(int n) {
        
      vector<string> ans;
      string out = "";
      int open = 0;
      int close = 0;

      solve(ans, out, open, close, n);
      return ans;

    }
};

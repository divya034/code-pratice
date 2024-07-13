class Solution {
public:
    bool isSafe(int i, int j, vector<pair<int,int>> &vis){
        for(auto x : vis){
            // if(i == x.first || j == x.second || abs(x.first - x.second) == abs(i - j)){
            //     return false;
            // }

            if(i == x.first || j == x.second || abs(x.first - i) == abs(x.second - j)){
                return false;
            }
        }
        return true;
    }

    void build_sol(vector<pair<int,int>> &vis, vector<string> &ans, int n, vector<vector<string>> &final){

        // for(auto i: vis){
        //     ans[i.first][i.second] = 'Q';
        // }

        // final.push_back(ans);

         vector<string> board(n, string(n, '.'));
        for(auto i: vis){
            board[i.first][i.second] = 'Q';
        }
        final.push_back(board);

        // here DIDNT SEE ANS back to original state after pushing into FINAL

    }
    void solve(vector<string> &ans, int n, vector<pair<int,int>> &vis, int col, vector<vector<string>> &final){

        if(col >= n){
            build_sol(vis, ans, n, final);
            return;
        }

        for(int row = 0; row <= n - 1; row++){
            if(isSafe(row, col, vis)){
                vis.push_back({row,col});

                solve(ans, n, vis, col + 1, final);

                vis.pop_back();
            }
        }
        

    }
    vector<vector<string>> solveNQueens(int n) {
       vector<vector<string>> final;
       vector<string> ans(n, string(n, '.'));

    //    vector<string> ans(n,string(n, ".");
       vector<pair<int,int>> vis;
       int col = 0;

       solve(ans, n, vis, col, final);

       return final;

    }
};

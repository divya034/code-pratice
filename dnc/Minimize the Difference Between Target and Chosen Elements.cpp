// For the first row, there are m calls
// For each of these m calls, there are again m calls = TOTAL M^2 calls for 2nd row

// This pattern continues for n rows, resulting in m^n recursive calls in total.


class Solution {
public:

    int solve(vector<vector<int>>& mat, int target, int row, int sum){
        
        if(row == mat.size()){
            return abs(target - sum);
        }
        
        int ans = INT_MAX;
        for(int col = 0; col < mat[0].size(); col++){
            ans = min(ans, solve(mat, target, row + 1, sum + mat[row][col]));
            // int recans = solve(mat, target, row + 1, sum + mat[row][col]);
            // ans = min(ans, recans);
        }

        return ans;
    }
    int minimizeTheDifference(vector<vector<int>>& mat, int target) {

        return solve(mat, target, 0, 0);
        
    }
};

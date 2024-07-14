// 2^n
Total Number of Calls:

At the top level (row 0), there is 1 call.
At the next level (row 1), there are 2 calls.
At the next level (row 2), there are 4 calls.
This pattern continues, leading to 2^n calls at the bottom level (row n-1).
This results in a total number of recursive calls that is exponential with respect to the number of rows in the triangle. Specifically, the total number of recursive calls can be represented as:
Total calls
This is a geometric series that sums to 

Total calls=1+2+4+…+2 
(n−1)
 

class Solution {
public:

    void solve(vector<vector<int>>& tri, int row, int col, int curr_sum, int &sum){
        if(row == tri.size()){
            sum = min(sum, curr_sum);
            return;
        }


        solve(tri, row + 1, col, curr_sum + tri[row][col], sum);
        solve(tri, row + 1, col + 1, curr_sum + tri[row][col], sum);

        return;

    }
    int minimumTotal(vector<vector<int>>& tri) {
        int sum = INT_MAX;

        solve(tri,0,0,0,sum);

        return sum;
    }
};

solve(4)
   |
   +-- solve(3) 
   |     |
   |     +-- solve(2) 
   |     |     |
   |     |     +-- solve(1)
   |     |     |     |
   |     |     |     +-- solve(0) -> 0
   |     |     |     +-- solve(-1) -> 0
   |     |     |
   |     |     +-- solve(0) -> 0
   |     |
   |     +-- solve(1)
   |           |
   |           +-- solve(0) -> 0
   |           +-- solve(-1) -> 0
   |
   +-- solve(2)
         |
         +-- solve(1)
         |     |
         |     +-- solve(0) -> 0
         |     +-- solve(-1) -> 0
         |
         +-- solve(0) -> 0


recur:
time complexity of O(2^n) due to the overlapping subproblems and lack of memoization.
space complexity is dominated by the recursion depth and is O(n)
class Solution {
public:
    int solve(vector<int>& heights, int i) {
        // Base case: If the frog is on the first step, no energy is required.
        if (i == 0) {
            return 0;
        }

        // Recursively calculate the energy required to jump to the current step (i)
        int left = solve(heights, i - 1) + abs(heights[i] - heights[i - 1]);

        int right = INT_MAX;  // Initialize as max value, because the 2-step jump may not exist if i < 2
        if (i > 1) {
            right = solve(heights, i - 2) + abs(heights[i] - heights[i - 2]);
        }

        // Return the minimum energy required to reach step i
        return min(left, right);
    }

    int frogJump(vector<int>& heights) {
        // Start solving from the last step (heights.size() - 1)
        return solve(heights, heights.size() - 1);
    }
};


Top down:
Since each step i (from 0 to n-1) is solved only once (due to memoization), 
the total number of recursive calls is O(n), where n is the number of steps (i.e., heights.size()).

SC: dp array, recur stack o(n)
class Solution {
public:
    int solve(vector<int> v, int i, vector<int> &dp){
        if(i <= 0){
            return 0;
        }

        if(dp[i] != -1){
            return dp[i];
        }

        int left = solve(v, i - 1, dp) + abs(v[i] - v[i-1]);
        int right = INT_MAX;
        if(i > 1)
        right = solve(v, i - 2, dp) + abs(v[i] - v[i-2]);

        return dp[i] = min(left, right);
    }
    int frogJump(vector<int>& heights) {
        vector<int> dp(heights.size(), -1);
        return solve(heights, heights.size() - 1, dp);
    }
};


Bottom up:
TC: o(n) loop
sc: o(n) dp arr

    int frogJump(vector<int>& heights) {
        vector<int> dp(heights.size(), -1);
        // return solve(heights, heights.size() - 1, dp);

        dp[0] = 0;

        for(int i = 1; i<heights.size(); i++){
            int left = dp[i - 1] + abs(heights[i] - heights[i-1]);
            int right = INT_MAX;
            if(i > 1){
                right = dp[i - 2] + abs(heights[i] - heights[i-2]);
            }

            dp[i] = min(left, right);
        }

        return dp[heights.size() - 1];
    }
};


space optimization:

o(n)
space o(1)

    int frogJump(vector<int>& heights) {
        int prev = 0;
        int prev2 = 0;
        
        for(int i = 1; i<heights.size(); i++){
            int fs = prev + abs(heights[i] - heights[i-1]);
            int ss = INT_MAX;
            if(i > 1){
                ss = prev2 + abs(heights[i] - heights[i-2]);
            }

            int curr = min(fs, ss); 
            // min cost to reach the current stone
            prev2 = prev;
            prev = curr;
        }

        return prev;
    }
};

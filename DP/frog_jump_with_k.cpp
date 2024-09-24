RECUR:
tc= O(N*K) BECAUSE FOR EACH n STEPS WE NEED k STEPS BEFORE IT
sc: The recursion depth is at most n, because we are moving 
from the last step (index n-1) down to the first step (index 0). Thus, the recursion stack will at most hold n calls.
class Solution {
public:
    int solve(vector<int>& h, int i, int k) {
        // Base case: if we're at step 0, no energy is needed
        if (i == 0) return 0;

        // Initialize minimum energy for this step as infinity
        int mini = INT_MAX;

        // Loop over the last 'k' steps
        for (int j = i - 1; j >= i - k && j >= 0; j--) {
            // Calculate the energy required to jump from step j to step i
            int jump = abs(h[i] - h[j]) + solve(h, j, k);
            // Track the minimum energy needed
            mini = min(mini, jump);
        }

        return mini;
    }

    int frogJump(vector<int>& heights, int k) {
        int ind = heights.size() - 1;
        return solve(heights, ind, k);
    }
};



TOP DOWN:
TC: o(n*k), UPTO, 
SC: O(N) stack + O(N) DP
class Solution {
public:
    int solve(vector<int>h, int i, int k,vector<int> &dp){
        if(i == 0) return 0;
        if(dp[i] != -1) return dp[i];
        
        int mini = INT_MAX;
        for(int j = i - 1; j >= i-k && j >= 0; j--){
            int jump = abs(h[i] - h[j]) + solve(h, j, k, dp);
            mini = min(mini, jump);
        }

        return dp[i] = mini;
    }
    int frogJump(vector<int>& heights, int k) {
        int mini = INT_MAX;
        int n = heights.size();
        int ind = heights.size() - 1;
        vector<int> dp(n, -1);
        return solve(heights, ind, k, dp);
    }
};



BOTTOM UP:
o(N*K)
SC: o(n)

class Solution {
public:
    int solve(vector<int>h, int i, int k,vector<int> &dp){
        if(i == 0) return 0;
        if(dp[i] != -1) return dp[i];
        
        int mini = INT_MAX;
        for(int j = i - 1; j >= i-k && j >= 0; j--){
            int jump = abs(h[i] - h[j]) + solve(h, j, k, dp);
            mini = min(mini, jump);
        }

        return dp[i] = mini;
    }
    int frogJump(vector<int>& heights, int k) {
        int n = heights.size();
        vector<int> dp(n, -1);

        dp[0] = 0;
        int mini;

        for(int i = 1; i<n; i++){
            int mini = INT_MAX;

            for(int j = 1; j<=k; j++){
                
                if(i-j >= 0){
                    int jump = abs(heights[i] - heights[i-j]) + dp[i-j];
                    mini = min(mini, jump);
                }
            }

            dp[i] = mini;
        }

        return dp[n-1];
    }
};




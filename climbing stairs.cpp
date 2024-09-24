recursion:
2^n
o(n) stack
class Solution {
public:
    int solve(int n){
        if(n == 0) return 1;
        if(n < 0) return 0;

        int left = solve(n - 1);
        int right = solve(n - 2);

        return left + right;
    }
    int climbStairs(int n) {
        
        return solve(n);
    }
};

TOP DOWN:
O(n) because each n value is computed only once, thanks to memoization
o(n) stack + o(n) dp arr
class Solution {
public:
    int solve(int n, vector<int> &dp){
        if(n == 0) return 1;
        if(n < 0) return 0;
        if(dp[n] != -1){
            return dp[n];
        }

        int left = solve(n - 1, dp);
        int right = solve(n - 2, dp);

        return dp[n] = left + right;
    }
    int climbStairs(int n) {
        vector<int> dp(n+1, -1);
        return solve(n, dp);
    }
};


Bottom up:
O(n): You iterate over the values from 2 to n, filling up the dp array.
Space Complexity:
O(n) space
class Solution {
public:
    int climbStairs(int n) {
        vector<int> dp(n+1, 1);

        dp[0] = 1;
        dp[1] = 1;

        for(int i = 2; i<=n; i++){
            dp[i] = dp[i-1] + dp[i-2];
        }

        return dp[n];
    }
};

space optimizations:
O(n)
o(1) space
class Solution {
public:
    int climbStairs(int n) {
        
        int prev = 1;
        int prev2 = 1;

        for(int i = 2; i<=n; i++){
            int curr = prev + prev2;
            prev2 = prev;
            prev = curr;
        }

        return prev;
    }
};

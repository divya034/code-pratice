recur:
The time complexity is exponential, O(2^N), where N is the size of the input vector nums.
The space complexity is O(N) due to the recursive calls, where N is the size of the input vector
class Solution {
public:
    int f(vector<int> nums, int i){
        if(i == 0){
            return nums[i];
        }
        if(i < 0){
            return 0;
        }

        int pick = nums[i] + f(nums, i - 2);
        int notpick = f(nums, i - 1);

        return max(pick, notpick);
    }
    int nonAdjacent(vector<int>& nums) {
        int n = nums.size();
        return f(nums, n-1);
    }
};


TOP DOWN:
 time complexity is O(N), where N is the size of the input vector nums
Space
depth of the recursion is at most N (in the worst case), so the recursion stack also uses O(N) space.
DP ARRAY

class Solution {
public:
    int f(vector<int> nums, int i, vector<int> &dp){
        if(i == 0){
            return nums[i];
        }
        if(i < 0){
            return 0;
        }

        if(dp[i] != -1){
            return dp[i];
        }

        int pick = nums[i] + f(nums, i - 2, dp);
        int notpick = f(nums, i - 1, dp);

        return dp[i] = max(pick, notpick);
    }
    int nonAdjacent(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(n+1, -1);
        
        return f(nums, n-1, dp);
    }
};



BOTTOM UP:
Time Complexity: O(N) — You are iterating through the array once.
Space Complexity: O(N) — You are using a dp array of size n.
class Solution {
public:
    int f(vector<int> nums, int i, vector<int> &dp){
        if(i == 0){
            return nums[i];
        }
        if(i < 0){
            return 0;
        }

        if(dp[i] != -1){
            return dp[i];
        }

        int pick = nums[i] + f(nums, i - 2, dp);
        int notpick = f(nums, i - 1, dp);

        return dp[i] = max(pick, notpick);
    }
    int nonAdjacent(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(n+1, -1);
        dp[0] = nums[0];
        int neg = 0;

        for(int i = 1; i<n; i++){
            int pick = nums[i];
            if(i > 1) pick += dp[i-2];

            int notpick = dp[i-1];

            dp[i] = max(pick, notpick);
        }
        
        return dp[n-1];
        // return f(nums, n-1, dp);
    }
};



SPACE OPTIMIZED:
TC: N
SC: o(1)

class Solution {
public:
    int nonAdjacent(vector<int>& nums) {
        int n = nums.size();
        int prev = nums[0];
        int prev2 = 0;

        for(int i = 1; i<n; i++){
            int pick = nums[i];
            if(i > 1) pick += prev2;

            int notpick = prev;

            int curr = max(pick, notpick);
            prev2 = prev;
            prev = curr;
        }
        
        return prev;
    }
};

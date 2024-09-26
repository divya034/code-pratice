class Solution {
public:
    int solve(vector<int> nums, int i) {
        int prev = nums[0];
        int prev2 = 0;

        for(int i = 1; i<nums.size(); i++){
            int pick = nums[i];
            if(i>1) pick += prev2;

            int notPick = nums[i - 1];
            int curr = max(pick, notPick);

            prev2 = prev;
            prev = curr;
        }

        return prev;
    }
    
    int houseRobber(vector<int>& money) {
        int n = money.size();

        vector<int> temp1, temp2;
        for(int i = 0; i<n; i++){
           if(i != n-1) temp1.push_back(money[i]);
           if(i != 0) temp2.push_back(money[i]);

        }

        int ans1 = solve(temp1, 0);
        int ans2 = solve(temp2, 0);

        return max(ans1, ans2);
    }
};


OR just with a bool saying if last was picked dont pick 1st element, if last wasnt picked pick the first element
class Solution {
public:
    int solve(vector<int> nums, int i, bool &flag) {
        if (i == 0) {
            return flag ? 0 : nums[0]; // Correct placement of closing brace
        }
        if (i < 0) {
            return 0;
        }

        int pick = nums[i];
        if (i > 1) pick += solve(nums, i - 2, flag); // Add the value from i - 2 if it exists

        int notpick = solve(nums, i - 1, flag); // Recursive call for not picking the current house

        return max(pick, notpick); // Return the maximum value
    }
    
    int houseRobber(vector<int>& money) {
        int n = money.size();

        // Call solve for the two cases
        int ans1 = solve(money, n - 1, false);
        int ans2 = solve(money, n - 1, true);

        return max(ans1, ans2);
    }
};

class Solution {
public:

    bool solve(vector<int>& nums, int i){
       
        if(i == nums.size() - 1){
            return true;
        }
       
       if(nums[i] == 0){
            return false;
        }

        if(i >= nums.size()){
            return false;
        }
        
        bool ans = false;
        for(int j = 1; j <= nums[i]; j++){
             ans = ans || solve(nums, i+j);
        }

        return ans;
    }

    bool canJump(vector<int>& nums) {
        return solve(nums, 0);
    }
};

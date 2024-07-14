// Thus, the number of recursive calls grows exponentially, not factorially. Here's why:

At level 0 (starting point), there's 1 call.
At level 1, there can be up to k calls.
At level 2, each of those k calls can again make up to k calls, resulting in k^2 calls.
This pattern continues, leading to an exponential growth in the number of calls.
  s, the time complexity is 
(K^N), where k is the maximum value in the array (bounded by n).

class Solution {
public:
    int solve(vector<int>& nums, int i, int jumps_c){
        if(i == nums.size() - 1){
            return jumps_c;
        }

        if(i >= nums.size()){
            return INT_MAX;
        }

        int jumps = INT_MAX;

        for(int j = 1; j <= nums[i]; j++){
            jumps = min(jumps, solve(nums, i+j, jumps_c + 1));
        }

        return jumps;
    }
    int jump(vector<int>& nums) {
        
        return solve(nums, 0, 0);
    }
};

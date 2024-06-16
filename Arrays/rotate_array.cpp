class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        int diff = k % n; 

        vector<int> temp;
        // make front elements
        for(int i = n - diff; i< n; i++){
           temp.push_back(nums[i]);
        }
      // i put i >=0 so the nums[-diff]

        for(int i = n - 1; i>=diff; i--){
            nums[i] = nums[i - diff];
        }

      // mistake: put i < k, its not the number of elements its the number of rotations
      // but number of rotations = no of elemets, just need the mod value

        for(int i = 0; i<diff; i++){
            nums[i] = temp[i];
        }
    }
};

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int > map;
        
        //value to indexes store
        for(int i=0; i<nums.size(); i++) {
            map[nums[i]] = i;
        }   
        //ab aapne har value k hr possible index ki mapping store krli h

        for(int i=0; i<nums.size(); i++) {
            int current = nums[i];
            int required = target - nums[i];
            if(map.find(required) != map.end() && map[required] != i) {
               return{i,map[required]};
            }
        }
        return {-1,-1};


    }
};

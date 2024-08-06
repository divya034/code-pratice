class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> m;
        int n = nums2.size();
        stack<int> s;

        for(int i = n-1; i >=0; i--){
            while(!s.empty() && s.top() <= nums2[i]){
                s.pop();
            }
            
            if(!s.empty()){
                m[nums2[i]] = s.top();
            }
            else{
                m[nums2[i]] = -1; 
            }

            s.push(nums2[i]);
        }

        vector<int> ans;

        for(auto i:nums1){
            ans.push_back(m[i]);
        }

        return ans;
    }
};

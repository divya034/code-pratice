class Solution {
public:
    int findPairs(vector<int>& arr, int k) {

        int i = 0;
        int j = 1;

        sort(arr.begin(), arr.end());
        // 1 1 3 4 5
        
        set<pair<int,int>> s;
        
        while(j < arr.size() && i < arr.size()){
            int diff = abs(arr[j] - arr[i]);
            if(i != j && diff == k){
                s.insert({arr[i], arr[j]});
                j++;
            }
            if(diff < k){
                j++;
            }
            else{
                i++;
            }

        }

        return s.size();



        // int  i = 0, j=1;
        // set<pair<int,int>> p;
        // sort(nums.begin(), nums.end());

        // while(j < nums.size()){
        //     int diff = abs(nums[j] - nums[i]);

        //     if(diff == k){
        //       p.insert({nums[i], nums[j]});
        //     }

        //     if(diff > k){
        //        i++;
        //     }

        //     else{
        //         j++;
        //     }

        //     if(i==j) j++;
        // }

        // return p.size();
    }
};

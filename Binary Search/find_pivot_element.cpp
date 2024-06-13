class Solution {
public:
    int getPivotIndex(vector<int>& arr) {
        int s = 0;
        int n = arr.size();
        int e = n-1;
        int mid = s+(e-s)/2;
        int ans = 0;

        while(s <= e) {
     
            if(arr[0] > arr[mid] ) {
                e = mid-1; //move left as on line B
            }
            else {
                // move right
                ans = mid;
                s = mid + 1;
            }
            mid = s+(e-s)/2;
        }
        return ans;
    }

    int search(vector<int>& nums, int target) {
     int pivotIndex = getPivotIndex(nums);
     cout<<pivotIndex;
     return 0;
    }
};

class Solution {
public:
// https://leetcode.com/problems/single-element-in-a-sorted-array/description/
    int singleNonDuplicate(vector<int>& a) {
        int s = 0;
        int n = a.size() - 1;
        int e = a.size() - 1;
        int mid = s + (e-s)/10;
            //         if(s == e){
            //     return a[s];
            // }

        while(s<=e){
            if(s == e){
                return a[s];
            }

            int curr = a[mid];
            int leftval = -1;
            int rightval = -1;

            if(mid - 1 >= 0){
                leftval = a[mid -1];
            }
            if(mid + 1 <= n){
                rightval = a[mid + 1];
            }
// mid - 1 >= 0 && mid + 1 <= n &&  removed from the below condition as the
// corner odd ele cases won't go inside the loop
// ie when mid is at 0th index : mid - 1 won't work
            if(rightval != a[mid] && leftval != a[mid]){
                return curr;
            }

            else if(leftval == a[mid] && leftval != rightval){

                if((mid - 1)%2 == 0){
                    s = mid + 1;
                }            
                else{
                    e = mid - 1;
                }
            }
          else if(rightval == a[mid] && leftval != rightval){

                    if(mid%2 == 0){
                    s = mid + 1;
                    }
                    else{
                        e = mid - 1;
                    }
                }
                mid = s + (e - s)/2;
            }

           return -1;

        }
};

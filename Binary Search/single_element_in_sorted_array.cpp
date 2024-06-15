class Solution {
public:
    int singleNonDuplicate(vector<int>& a) {
        int s = 0;
        int n = a.size() - 1;
        int e = a.size() - 1;
        int mid = s + (e-s)/10;

        while(s<=e){
            if(s == e){
                return a[s];
            }

            // int curr = nums[mid];
            // int leftval = 

            if(mid - 1 >= 0 && mid + 1 <= n && a[mid + 1] != a[mid] && a[mid - 1] != a[mid]){
                return a[mid];
            }

            else if(mid-1 >= 0 && a[mid - 1] == a[mid]){

                if((mid - 1)%2 == 0){
                    s = mid + 1;
                }            
                else{
                    e = mid - 1;
                }
            }
                else if(mid + 1 && a[mid + 1] == a[mid]){

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

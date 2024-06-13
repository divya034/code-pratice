class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
       
        int s = 0;
        int n = arr.size();
        int e = n-1;
        int mid = s + (e-s)/2;
        int ansIndex = -1;

        while(s < e) {
            if(mid - 1 >= 0 && mid + 1 <= n-1 && (arr[mid-1] < arr[mid] && arr[mid] > arr[mid+1])) {
                return mid;
            }
            if (arr[mid] < arr[mid+ 1]){
               s = mid + 1;
            }
            else if(arr[mid+ 1] < arr[mid]){
                e = mid;
            }
            mid = s + (e-s)/2;
        }
        return s;

        // int lo = 0, hi = arr.size() - 1;
        // while (lo < hi) {
        //     int mid = lo + (hi - lo) / 2;
        //     if (arr[mid] > arr[mid+ 1]) 
        //        hi = mid;  
              
        //     else
        //        lo = mid + 1;

        
        // return lo;  
    }
};

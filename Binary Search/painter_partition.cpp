class Solution
{
  public:
 bool isPossible(int arr[], int k, int n, long long mid){
      long long time = 0;

      int p = 1;
      
      for(int i = 0; i<=n-1; i++){
          
         if(arr[i] > mid){
             return false;
         }
         
         if(time + arr[i] <= mid){
            time += arr[i];

         }
         else{
            p++;
            time = arr[i];
             
            if(p>k) return false;
         }
         
      }
      
      return true;

   }
    long long minTime(int arr[], int n, int k)
    {
        long long s = 0; 
        long long sum = 0;
        // Minimum possible distance
        for(int i = 0; i<n; i++){
            sum += arr[i];
        }
        long long e = sum; // Maximum possible distance
          
          long long mid = s + (e-s)/2;
          long long ans = 0;
        //   possible time to finish all the boards
        // minimi
        
          while(s <= e){
              if(isPossible(arr, k, n, mid)){
                  ans = mid;
                  e = mid - 1;
              }
              else{
                  s = mid + 1;
              }
              
              mid = s + (e-s)/2;
          }
          
          return ans;
    }
};

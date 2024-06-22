class Solution {
public:

   bool isPossible(vector<int> stalls, int k, int n, int mid){
      int cows = 1;
      int pos = stalls[0]; //first cow at 0th position
       
      for(int i = 1; i<n; i++){
        //   our work is to just make sure minimum dist is mid
          if(stalls[i] - pos >= mid){
              cows++;
              if(cows == k){
                  return true;
              }
              
              pos = stalls[i];
              
          }
        
      }
       
      return false;
    

   }

    int solve(int n, int k, vector<int> &stalls) {
          
        sort(stalls.begin(), stalls.end());
        int s = 1; // Minimum possible distance
        int e = stalls[n-1] - stalls[0]; // Maximum possible distance
          
          int mid = s + (e-s)/2;
          int ans = 0;
          
          while(s <= e){
              if(isPossible(stalls, k, n, mid)){
                  ans = mid;
                  s = mid + 1;
              }
              else{
                  e = mid - 1;
              }
              
              mid = s + (e-s)/2;
          }
          
          return ans;
        
    }
};

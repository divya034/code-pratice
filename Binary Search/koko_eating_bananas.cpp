class Solution {
public:
    bool canEatAll(int h, vector<int>& piles, int k){
        long long int hrs = 0;

        for(auto i : piles){
          // make double to take ceil to get next hr ka value
            hrs += ceil((double)i / k);
        }

        return hrs <= h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        
        int s = 1;
        // int it = max_element(piles.begin(), piles.end());
        // returns iterator
        int e = *max_element(piles.begin(), piles.end());;

        int mid = s + (e-s)/2;
        int ans = -1;

        while(s<=e){
            if(canEatAll(h, piles, mid)){
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

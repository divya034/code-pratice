class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend == INT_MIN && divisor == -1) {
            return INT_MAX;
        }

        int ans_neg = 0;
        if(divisor < 0 && dividend > 0){
            ans_neg = 1;
        }
        else if(divisor > 0 && dividend < 0){
            ans_neg = 1;
        }

        dividend = abs(dividend);
        divisor = abs(divisor);
        long long s = 0;
        long long e = dividend;
        long long mid = s + (e-s)/2;
        long long ans;

        while(s<=e){
            long long prod = mid * divisor;

            if(prod == dividend){
                ans = mid;
                break;
            }

            else if(prod < dividend){
                ans = mid;
                s = mid + 1;
            }
            
            else{
                e = mid - 1;
            }

            mid = s + (e - s)/2;
            
        }
       
       if(ans_neg == 1) ans = -ans;

       return ans;
    }
};

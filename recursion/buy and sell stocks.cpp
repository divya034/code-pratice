class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = INT_MIN;
        int day = INT_MAX; 
        // maximize profit
        // minimize price

        for(int i = 0; i<prices.size(); i++){
            day = min(prices[i], day);
            int day_p = prices[i] - day;
            
            profit = max(profit, day_p);


        }

        // return profit;

        return profit;
    }
};

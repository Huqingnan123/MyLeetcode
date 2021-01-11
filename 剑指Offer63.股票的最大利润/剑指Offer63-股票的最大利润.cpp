class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() <= 1)
            return 0;
        int dp[prices.size()];     //only one chance for buy and sale
        int minPrice = prices[0];  //remember the minPrice
        dp[0] = 0;
        for(int i = 1; i < prices.size(); i++)
        {
            dp[i] = max(dp[i-1], prices[i] - minPrice);
            minPrice = min(prices[i], minPrice);
        }
        return dp[prices.size()-1];
    }
};
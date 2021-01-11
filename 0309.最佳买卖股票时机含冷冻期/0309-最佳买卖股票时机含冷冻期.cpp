class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() <= 1)
            return 0;
        int dp[prices.size()][3];
        dp[0][0] = -prices[0];//已持有股票能获得的最大现金
        dp[0][1] = 0;         //未持有股票(下一天能购买)
        dp[0][2] = 0;         //未持有股票(下一天冷冻期)
        for(int i = 1; i < prices.size(); i++)
        {
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] - prices[i]);
            dp[i][1] = max(dp[i - 1][1], dp[i - 1][2]);
            dp[i][2] = dp[i - 1][0] + prices[i];
        }
        return max(dp[prices.size()-1][1],dp[prices.size()-1][2]);
    }
};
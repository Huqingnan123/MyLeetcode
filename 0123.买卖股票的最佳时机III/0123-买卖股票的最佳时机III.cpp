class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() <= 1) 
            return 0;
        //每一天都存在0~4一共五种不同的操作状态
        //0:未进行过操作 1:买入了一次 2:卖出了一次 3:买入了两次 4:卖出了两次
        int dp[prices.size()][5];
        dp[0][0] = 0;
        dp[0][1] = -prices[0];
        dp[0][2] = 0;
        dp[0][3] = -prices[0];
        dp[0][4] = 0;
        for (int i = 1; i < prices.size(); i++)
        {
            //dp[i]的状态沿用dp[i-1]的相同状态或者由前一个状态演变而来
            dp[i][0] = dp[i - 1][0];
            dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] - prices[i]);
            dp[i][2] = max(dp[i - 1][2], dp[i - 1][1] + prices[i]);
            dp[i][3] = max(dp[i - 1][3], dp[i - 1][2] - prices[i]);
            dp[i][4] = max(dp[i - 1][4], dp[i - 1][3] + prices[i]);
        }
        return dp[prices.size() - 1][4];
    }
};
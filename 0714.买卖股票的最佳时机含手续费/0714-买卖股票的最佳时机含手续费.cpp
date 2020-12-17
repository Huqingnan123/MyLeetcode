class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        //dp[i][0]表示第i+1天“不持有股票”的最大利益，可能是第i天本来就不持有，也可能是第i天持有并在第i+1天卖出
        //dp[i][1]表示第i+1天“持有该股票”的最大利益，可能是第i天本来就持有，也可能是第i天不持有并在第i+1天买入
        if(prices.size() <= 1)
            return 0;
        int dp[prices.size()][2];  
        dp[0][0] = 0;
        dp[0][1] = -prices[0];
        for(int i = 1; i < prices.size(); i++)
        {
            //买的时候只用支付股票价格，完成一买一卖就要交手续费fee 
            dp[i][0] = max(dp[i-1][0], dp[i-1][1] + prices[i] - fee);   
            dp[i][1] = max(dp[i-1][1], dp[i-1][0] - prices[i]);
        }
        return dp[prices.size()-1][0];
    }
};
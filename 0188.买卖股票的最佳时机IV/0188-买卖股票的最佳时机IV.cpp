class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        if (prices.size() <= 1 || k == 0) 
            return 0;
        //最多完成k笔交易，就会存在0~2k一共2k+1种不同的操作状态
        //每一天都存在0~2k一共2k+1种不同的操作状态，可参照Ⅲ题解析过程
        int dp[prices.size()][2*k+1];
        //Intialize State
        for(int i = 0; i < 2*k + 1; i++)
        {
            //不买入就不扣钱，否则就扣钱
            if(i%2 == 0)
                dp[0][i] = 0;
            else
                dp[0][i] = -prices[0];
        }
        
        for (int i = 1; i < prices.size(); i++)
        {
            //dp[i]的状态沿用dp[i-1]的相同状态或者由前一个状态演变而来，取MAX
            dp[i][0] = dp[i - 1][0];
            for(int j = 1; j < 2*k + 1; j++)
            {
                //卖出了j/2次
                if(j%2 == 0)
                    dp[i][j] = max(dp[i - 1][j], dp[i - 1][j-1] + prices[i]);
                //买入了j/2 + 1次
                else
                    dp[i][j] = max(dp[i - 1][j], dp[i - 1][j-1] - prices[i]);
            }
        }
        return dp[prices.size() - 1][2*k];
    }
};
class Solution {
public:
    int maxProfit(vector<int>& prices) {
    // --- DP思想，时间复杂度O(n),空间复杂度O(n) 
        if(prices.size() <= 1)
            return 0;
        //dp[i]表示前 i 天可以获得的最大利润
        int dp[prices.size()];
        //minPrice记录之前出现的最小价格
        int minPrice = prices[0];
        dp[0] = 0;
        for(int i = 1; i < prices.size(); i++)
        {
            dp[i] = max(dp[i-1],prices[i] - minPrice);
            minPrice = min(minPrice,prices[i]);
        }
        return dp[prices.size()-1];

    // --- 维护两个变量，时间复杂度O(n),空间复杂度O(1)
        // if(prices.size() <= 1)
        //     return 0;
        // //maxProfit表示前 i 天可以获得的最大利润,仅存有一次买卖，故可以不用dp动态规划
        // int maxProfit = 0;
        // //minPrice记录之前出现的最小价格
        // int minPrice = prices[0];
        // for(auto price : prices)
        // {
        //     maxProfit = max(maxProfit,price - minPrice);
        //     minPrice = min(minPrice,price);
        // }
        // return maxProfit;
    }
};
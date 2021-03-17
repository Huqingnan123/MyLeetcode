class Solution {
public:

    // 1、朴素二维dp (dp[i][j]表示用区间0-i的硬币种类组成总额j的组合总数)
    // dp[i][j] = dp[i][j - coins[i]] + dp[i-1][j]
    
    // 2、一维dp空间优化
    int change(int amount, vector<int>& coins) {
        vector<int> dp(amount + 1, 0);
        dp[0] = 1;
        // 遍历硬币种类
        for (int i = 0; i < coins.size(); i++) { 
            for (int j = coins[i]; j <= amount; j++) { 
                dp[j] += dp[j - coins[i]];
            }
        }
        return dp[amount];
    }
};
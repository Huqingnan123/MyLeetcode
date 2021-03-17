class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        //初始化为INT_MAX-1防止+1溢出
        vector<int> dp(amount+1, INT_MAX - 1);
        dp[0] = 0;
        for(int i = 1; i <= amount; i++) {
            for(int j = 0; j < coins.size(); j++) {
                if(coins[j] <= i) {
                    int remain = i - coins[j];
                    dp[i] = min(dp[remain] + 1, dp[i]);
                }
            }
        }
        return (dp[amount] == INT_MAX - 1) ? -1 : dp[amount] ;
    }
};
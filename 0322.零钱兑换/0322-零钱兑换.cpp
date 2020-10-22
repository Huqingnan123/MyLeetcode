class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<int> dp(amount + 1, INT_MAX-1);
        dp[0] = 0;        //初始化边界，amount=0的时候0枚硬币
        int minnum;
        for (int sum = 1; sum <= amount; sum++)
        {
            minnum = INT_MAX;
            for (int i = 0; i < n; i++)
            {
                if (sum - coins[i] < 0)    //很大的硬币不要
                    continue;
                minnum = min(minnum, dp[sum - coins[i]] + 1);  //取二者最小值作为dp[sum]
            }
            if (minnum != INT_MAX)
                dp[sum] = minnum;
        }
        return ((dp[amount] == INT_MAX-1)? -1 : dp[amount]);
    }
};
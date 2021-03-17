class Solution {
public:

    // 1�����ض�άdp (dp[i][j]��ʾ������0-i��Ӳ����������ܶ�j���������)
    // dp[i][j] = dp[i][j - coins[i]] + dp[i-1][j]
    
    // 2��һάdp�ռ��Ż�
    int change(int amount, vector<int>& coins) {
        vector<int> dp(amount + 1, 0);
        dp[0] = 1;
        // ����Ӳ������
        for (int i = 0; i < coins.size(); i++) { 
            for (int j = coins[i]; j <= amount; j++) { 
                dp[j] += dp[j - coins[i]];
            }
        }
        return dp[amount];
    }
};
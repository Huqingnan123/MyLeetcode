#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<int> dp(amount + 1, INT_MAX-1);
        dp[0] = 0;
        int minnum;
        for (int sum = 1; sum <= amount; sum++)
        {
            minnum = INT_MAX;
            if (dp[sum] != INT_MAX-1)
                continue;
            for (int i = 0; i < n; i++)
            {
                if (sum - coins[i] < 0)
                    continue;
                minnum = min(minnum, dp[sum - coins[i]] + 1);
            }
            if (minnum != INT_MAX)
                dp[sum] = minnum;
        }
        cout << ((dp[amount] == INT_MAX - 1) ? -1 : dp[amount]);
        return ((dp[amount] == INT_MAX-1)? -1 : dp[amount]);
    }
};
int main()
{
    Solution s;
    vector<int> vec{ 186,419,83,408 };
    int amount = 6249;
    s.coinChange(vec, amount);
    return 0;
}
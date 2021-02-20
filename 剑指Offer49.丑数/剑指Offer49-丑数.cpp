class Solution {
public:
    int nthUglyNumber(int n) {
        int dp[n];
        dp[0] = 1;
        // 三个index都是从0每一次最多加一，保证之前每一个数都计算了乘以2、3、5之后的“丑数”
        // index2表示计算next2时，与质因子2相乘的数的索引index
        // index3表示计算next3时，与质因子3相乘的数的索引index
        // index5表示计算next5时，与质因子5相乘的数的索引index
        int index2 = 0, index3 = 0, index5 = 0;
        for(int i = 1; i < n; i++)
        {
            int next2 = dp[index2] * 2;
            int next3 = dp[index3] * 3;
            int next5 = dp[index5] * 5;
            //选取最小的next作为dp[i]，选完之后相应的乘数index要加一
            dp[i] = min(next2, min(next3, next5));
            if(dp[i] == next2)
                index2++;
            if(dp[i] == next3)
                index3++;
            if(dp[i] == next5)
                index5++;
        }
        return dp[n-1];
    }
};
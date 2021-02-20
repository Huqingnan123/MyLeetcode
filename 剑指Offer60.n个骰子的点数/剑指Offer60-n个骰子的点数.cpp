class Solution {
public:
    vector<double> dicesProbability(int n) {
        vector<vector<double>> dp(n+1, vector<double>(5*n + 1));
        //第一个骰子的各点数概率结果
        for(int i = 0; i < 6; i++)
            dp[1][i] = double(1) / 6;
        //n个骰子的点数概率结果基于n-1个骰子的结果计算
        for(int i = 2; i <= n; i++)
        {
            //n个骰子一共有 n ~ 6n 共5*n + 1种点数结果，一一计算出来
            for(int index = 0; index < 5*i + 1; index++)
            {
                //某一种特定点数和的概率之和（基于之前n-1个骰子的情况计算）
                //遍历n-1个骰子的概率浮点数数组，综合计算得到n个骰子的结果
                for(int preIndex = 0; preIndex < 5*i - 4; preIndex++)
                {
                    //D_value是需要第n个骰子补充的点数，在1~6之间就可以累加概率
                    int D_value = index - preIndex + 1;
                    if(D_value >= 1 && D_value <= 6)
                        dp[i][index] += dp[i-1][preIndex] / 6;
                }    
            }
        }
        return dp[n];
    }
};
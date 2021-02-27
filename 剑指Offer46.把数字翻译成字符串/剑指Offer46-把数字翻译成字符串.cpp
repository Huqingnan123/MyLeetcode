class Solution {
public: 
    int translateNum(int num) {
        string numStr = to_string(num);
        int n = numStr.size();
        // dp[i]代表以xi为结尾的数字翻译成字符串的种类数，dp[i] = dp[i-1] 或 dp[i-1] + dp[i-2]
        // Xi一定可以单独进行翻译，所以至少有dp[i-1]；关键看Xi-1Xi是否可以合并起来翻译，是否有dp[i-2]
        // 当数字为2位数：12的时候，显然可以翻译成"bc"或者"m"，所以初始化dp[0] = 1
        int dp[n+1];
        dp[0] = 1;
        dp[1] = 1;
        for(int i = 2; i <= n; i++)
        {
            // 查看Xi-1Xi两位数字的数值大小，[10,25]之间Xi-1Xi两位就可以合并翻译
            int value = stoi(numStr.substr(i-2, 2));
            if(value >= 10 && value <= 25)
                dp[i] = dp[i-1] + dp[i-2];
            else
                dp[i] = dp[i-1];
        }
        return dp[n];
    }
};
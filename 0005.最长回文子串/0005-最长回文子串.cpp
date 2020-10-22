class Solution {
public:
    string longestPalindrome(string s) {
        int length = s.size();
        vector<vector<int>> dp(length,vector<int>(length));   //初始化全0
        int result_begin = 0;
        int maxlen = 1;
        int i,j,k;
        for(i = 0; i < length; i++)              //n次循环，从“对角线”往“角”上走沿斜线顺次赋值
            for(j = 0; j+i < length; j++)
            {
                k = j+i;          //i代表j,k之间的差值，比如第二轮(0,1),第三轮(0,2),第四轮(0,3)等
                if(i == 0)
                    dp[j][j] = 1;   //dp[i][j]=1代表s[i,j]回文
                else if(i == 1)
                    dp[j][k] = (s[j] == s[k]);
                else
                    dp[j][k] = dp[j+1][k-1] && (s[j] == s[k]);
                if(dp[j][k] && i+1 > maxlen)
                {
                    result_begin = j;
                    maxlen = i+1;
                }
            }
        return  s.substr(result_begin,maxlen);
    }
};
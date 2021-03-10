class Solution {
public:
    string longestPalindrome(string s) {
        int dp[s.size()][s.size()];
        int start = 0;
        int maxlen = 1;
        for(int i = 0; i < s.size(); i++)
            dp[i][i] = 1;
        for(int len = 2; len <= s.size(); len++) {
            //控制[i,j]区间字符串的长度为len
            for(int i = 0; i <= s.size() - len; i++) {
                int j = i + len - 1;
                if(len == 2)
                    dp[i][j] = (s[i] == s[j]);
                else
                    dp[i][j] = dp[i+1][j-1] && (s[i] == s[j]);
                if(dp[i][j] && len > maxlen) {
                    maxlen = len;
                    start = i;
                }
            }
        }
        return s.substr(start, maxlen);
    }
};
class Solution {
public:
    bool isMatch(string s, string p) {
        int sLen = s.length(), pLen = p.length();
        vector<vector<bool> > dp(sLen + 1, vector<bool>(pLen + 1, false));
        // s,p��Ϊ���ַ���""ƥ��true
        dp[0][0] = true;
        for(int i = 2; i <= pLen; i++)
        {
            // �жϳ�ʼƥ��λ��
            if(p[i - 1] == '*')
                dp[0][i] = dp[0][i - 2]; 
        }

        for(int i = 1; i <= sLen; i++)
        {
            for(int j = 1; j <= pLen; j++)
            {
                if(s[i - 1] == p[j - 1] || p[j - 1] == '.')
                    dp[i][j] = dp[i - 1][j - 1];
                else if(p[j - 1] == '*')
                {
                    if(p[j - 2] != s[i - 1] && p[j - 2] != '.')
                        dp[i][j] = dp[i][j - 2];
                    // else��֧��Ҫôp[j-2] == s[i-1]��Ҫôp[i-2] == '.'
                    else 
                        dp[i][j] = dp[i][j - 2] || dp[i - 1][j]; 
                }
                else 
                    dp[i][j] = false;
            }
        }
        return dp[sLen][pLen];
    }
};
class Solution {
public:
    string longestPalindrome(string s) {
        int length = s.size();
        vector<vector<int>> dp(length,vector<int>(length));   //��ʼ��ȫ0
        int result_begin = 0;
        int maxlen = 1;
        int i,j,k;
        for(i = 0; i < length; i++)              //n��ѭ�����ӡ��Խ��ߡ������ǡ�������б��˳�θ�ֵ
            for(j = 0; j+i < length; j++)
            {
                k = j+i;          //i����j,k֮��Ĳ�ֵ������ڶ���(0,1),������(0,2),������(0,3)��
                if(i == 0)
                    dp[j][j] = 1;   //dp[i][j]=1����s[i,j]����
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
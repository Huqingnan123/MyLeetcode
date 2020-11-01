class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> My_Dict; 
        for(auto& str : wordDict)
            My_Dict.insert(str);              //将字典里面的单词存进unordered_set中
        bool dp[s.size()+1];                  //dp[i]表示当前“长度为i的字符子串能否被正确分词”
        memset(dp,0,sizeof(dp));
        dp[0] = true;                         //边界初始化
        for(int i = 1;i<=s.size();i++)
        {
            for(int j = 0; j < i; j++)        //j从0开始，为了考虑s[0,i]就整个存在于字典中的情形    
            {
                //“转移方程”： 当dp[j] = true 并且 s[j,i]这个单词在字典中存在，dp[i] = true
                dp[i] |= (dp[j] && My_Dict.find(s.substr(j,i-j))!=My_Dict.end());
                if(dp[i] == true)
                    break;
            }
        }
        return dp[s.size()];                  //dp[s.size()]即为s是否能被分串
    }
};
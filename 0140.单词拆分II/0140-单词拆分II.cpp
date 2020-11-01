class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        if(wordBreak_judge(s,wordDict) == false)    //先进行是否能划分的判断，防止匹配超时
            return {};
        //dp[i]保存着长度为i+1的字符串可以划分成的所有句子
        vector<vector<string>> dp(s.size() + 1, vector<string>{});

        for (int i = 0; i < s.size(); i++) 
        {
            if (i != 0 && dp[i].empty())     //dp[i]没有保存任何切割集,不可划分情形
                continue;
            for (auto& word : wordDict) 
            {
                int boarder = i + word.size();
                //当从位置i开始匹配到一个word的时候，添加进dp[i+word.size()]中
                if (boarder <= s.size() && s.substr(i,word.size()) == word)
                {
                    if (i == 0) 
                    {
                        dp[boarder].push_back(word);
                        continue;
                    }
                    else
                    {
                        //dp[boarder]中每个句子都加上新的空格和word
                        for (auto& d : dp[i])
                            dp[boarder].push_back(d + " " + word);
                    }
                }
            }
        }
        return dp[s.size()];
    }

    //采用139.单词划分的代码先判断是否能被拆分
    bool wordBreak_judge(string s, vector<string>& wordDict){
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
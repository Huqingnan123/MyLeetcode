class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        if(wordBreak_judge(s,wordDict) == false)    //�Ƚ����Ƿ��ܻ��ֵ��жϣ���ֹƥ�䳬ʱ
            return {};
        //dp[i]�����ų���Ϊi+1���ַ������Ի��ֳɵ����о���
        vector<vector<string>> dp(s.size() + 1, vector<string>{});

        for (int i = 0; i < s.size(); i++) 
        {
            if (i != 0 && dp[i].empty())     //dp[i]û�б����κ��и,���ɻ�������
                continue;
            for (auto& word : wordDict) 
            {
                int boarder = i + word.size();
                //����λ��i��ʼƥ�䵽һ��word��ʱ����ӽ�dp[i+word.size()]��
                if (boarder <= s.size() && s.substr(i,word.size()) == word)
                {
                    if (i == 0) 
                    {
                        dp[boarder].push_back(word);
                        continue;
                    }
                    else
                    {
                        //dp[boarder]��ÿ�����Ӷ������µĿո��word
                        for (auto& d : dp[i])
                            dp[boarder].push_back(d + " " + word);
                    }
                }
            }
        }
        return dp[s.size()];
    }

    //����139.���ʻ��ֵĴ������ж��Ƿ��ܱ����
    bool wordBreak_judge(string s, vector<string>& wordDict){
        unordered_set<string> My_Dict; 
        for(auto& str : wordDict)
            My_Dict.insert(str);              //���ֵ�����ĵ��ʴ��unordered_set��
        bool dp[s.size()+1];                  //dp[i]��ʾ��ǰ������Ϊi���ַ��Ӵ��ܷ���ȷ�ִʡ�
        memset(dp,0,sizeof(dp));
        dp[0] = true;                         //�߽��ʼ��
        for(int i = 1;i<=s.size();i++)
        {
            for(int j = 0; j < i; j++)        //j��0��ʼ��Ϊ�˿���s[0,i]�������������ֵ��е�����    
            {
                //��ת�Ʒ��̡��� ��dp[j] = true ���� s[j,i]����������ֵ��д��ڣ�dp[i] = true
                dp[i] |= (dp[j] && My_Dict.find(s.substr(j,i-j))!=My_Dict.end());
                if(dp[i] == true)
                    break;
            }
        }
        return dp[s.size()];                  //dp[s.size()]��Ϊs�Ƿ��ܱ��ִ�
    }
};
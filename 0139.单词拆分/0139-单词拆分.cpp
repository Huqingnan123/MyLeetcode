class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
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
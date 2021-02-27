class Solution {
public: 
    int translateNum(int num) {
        string numStr = to_string(num);
        int n = numStr.size();
        // dp[i]������xiΪ��β�����ַ�����ַ�������������dp[i] = dp[i-1] �� dp[i-1] + dp[i-2]
        // Xiһ�����Ե������з��룬����������dp[i-1]���ؼ���Xi-1Xi�Ƿ���Ժϲ��������룬�Ƿ���dp[i-2]
        // ������Ϊ2λ����12��ʱ����Ȼ���Է����"bc"����"m"�����Գ�ʼ��dp[0] = 1
        int dp[n+1];
        dp[0] = 1;
        dp[1] = 1;
        for(int i = 2; i <= n; i++)
        {
            // �鿴Xi-1Xi��λ���ֵ���ֵ��С��[10,25]֮��Xi-1Xi��λ�Ϳ��Ժϲ�����
            int value = stoi(numStr.substr(i-2, 2));
            if(value >= 10 && value <= 25)
                dp[i] = dp[i-1] + dp[i-2];
            else
                dp[i] = dp[i-1];
        }
        return dp[n];
    }
};
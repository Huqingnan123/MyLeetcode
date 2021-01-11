class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        if (prices.size() <= 1 || k == 0) 
            return 0;
        //������k�ʽ��ף��ͻ����0~2kһ��2k+1�ֲ�ͬ�Ĳ���״̬
        //ÿһ�춼����0~2kһ��2k+1�ֲ�ͬ�Ĳ���״̬���ɲ��բ����������
        int dp[prices.size()][2*k+1];
        //Intialize State
        for(int i = 0; i < 2*k + 1; i++)
        {
            //������Ͳ���Ǯ������Ϳ�Ǯ
            if(i%2 == 0)
                dp[0][i] = 0;
            else
                dp[0][i] = -prices[0];
        }
        
        for (int i = 1; i < prices.size(); i++)
        {
            //dp[i]��״̬����dp[i-1]����ͬ״̬������ǰһ��״̬�ݱ������ȡMAX
            dp[i][0] = dp[i - 1][0];
            for(int j = 1; j < 2*k + 1; j++)
            {
                //������j/2��
                if(j%2 == 0)
                    dp[i][j] = max(dp[i - 1][j], dp[i - 1][j-1] + prices[i]);
                //������j/2 + 1��
                else
                    dp[i][j] = max(dp[i - 1][j], dp[i - 1][j-1] - prices[i]);
            }
        }
        return dp[prices.size() - 1][2*k];
    }
};
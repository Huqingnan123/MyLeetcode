class Solution {
public:
    vector<double> dicesProbability(int n) {
        vector<vector<double>> dp(n+1, vector<double>(5*n + 1));
        //��һ�����ӵĸ��������ʽ��
        for(int i = 0; i < 6; i++)
            dp[1][i] = double(1) / 6;
        //n�����ӵĵ������ʽ������n-1�����ӵĽ������
        for(int i = 2; i <= n; i++)
        {
            //n������һ���� n ~ 6n ��5*n + 1�ֵ��������һһ�������
            for(int index = 0; index < 5*i + 1; index++)
            {
                //ĳһ���ض������͵ĸ���֮�ͣ�����֮ǰn-1�����ӵ�������㣩
                //����n-1�����ӵĸ��ʸ��������飬�ۺϼ���õ�n�����ӵĽ��
                for(int preIndex = 0; preIndex < 5*i - 4; preIndex++)
                {
                    //D_value����Ҫ��n�����Ӳ���ĵ�������1~6֮��Ϳ����ۼӸ���
                    int D_value = index - preIndex + 1;
                    if(D_value >= 1 && D_value <= 6)
                        dp[i][index] += dp[i-1][preIndex] / 6;
                }    
            }
        }
        return dp[n];
    }
};
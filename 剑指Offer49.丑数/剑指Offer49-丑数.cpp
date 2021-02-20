class Solution {
public:
    int nthUglyNumber(int n) {
        int dp[n];
        dp[0] = 1;
        // ����index���Ǵ�0ÿһ������һ����֤֮ǰÿһ�����������˳���2��3��5֮��ġ�������
        // index2��ʾ����next2ʱ����������2��˵���������index
        // index3��ʾ����next3ʱ����������3��˵���������index
        // index5��ʾ����next5ʱ����������5��˵���������index
        int index2 = 0, index3 = 0, index5 = 0;
        for(int i = 1; i < n; i++)
        {
            int next2 = dp[index2] * 2;
            int next3 = dp[index3] * 3;
            int next5 = dp[index5] * 5;
            //ѡȡ��С��next��Ϊdp[i]��ѡ��֮����Ӧ�ĳ���indexҪ��һ
            dp[i] = min(next2, min(next3, next5));
            if(dp[i] == next2)
                index2++;
            if(dp[i] == next3)
                index3++;
            if(dp[i] == next5)
                index5++;
        }
        return dp[n-1];
    }
};
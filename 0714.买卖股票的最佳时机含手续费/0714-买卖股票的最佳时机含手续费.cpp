class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        //dp[i][0]��ʾ��i+1�조�����й�Ʊ����������棬�����ǵ�i�챾���Ͳ����У�Ҳ�����ǵ�i����в��ڵ�i+1������
        //dp[i][1]��ʾ��i+1�조���иù�Ʊ����������棬�����ǵ�i�챾���ͳ��У�Ҳ�����ǵ�i�첻���в��ڵ�i+1������
        if(prices.size() <= 1)
            return 0;
        int dp[prices.size()][2];  
        dp[0][0] = 0;
        dp[0][1] = -prices[0];
        for(int i = 1; i < prices.size(); i++)
        {
            //���ʱ��ֻ��֧����Ʊ�۸����һ��һ����Ҫ��������fee 
            dp[i][0] = max(dp[i-1][0], dp[i-1][1] + prices[i] - fee);   
            dp[i][1] = max(dp[i-1][1], dp[i-1][0] - prices[i]);
        }
        return dp[prices.size()-1][0];
    }
};
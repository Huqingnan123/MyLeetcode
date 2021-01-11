class Solution {
public:
    int maxProfit(vector<int>& prices) {
    // --- DP˼�룬ʱ�临�Ӷ�O(n),�ռ临�Ӷ�O(n) 
        if(prices.size() <= 1)
            return 0;
        //dp[i]��ʾǰ i ����Ի�õ��������
        int dp[prices.size()];
        //minPrice��¼֮ǰ���ֵ���С�۸�
        int minPrice = prices[0];
        dp[0] = 0;
        for(int i = 1; i < prices.size(); i++)
        {
            dp[i] = max(dp[i-1],prices[i] - minPrice);
            minPrice = min(minPrice,prices[i]);
        }
        return dp[prices.size()-1];

    // --- ά������������ʱ�临�Ӷ�O(n),�ռ临�Ӷ�O(1)
        // if(prices.size() <= 1)
        //     return 0;
        // //maxProfit��ʾǰ i ����Ի�õ��������,������һ���������ʿ��Բ���dp��̬�滮
        // int maxProfit = 0;
        // //minPrice��¼֮ǰ���ֵ���С�۸�
        // int minPrice = prices[0];
        // for(auto price : prices)
        // {
        //     maxProfit = max(maxProfit,price - minPrice);
        //     minPrice = min(minPrice,price);
        // }
        // return maxProfit;
    }
};
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        for(int i = 0, j = 0; j < prices.size() - 1;)         //˫ָ���ƶ�
        {
            if(prices[j+1] >= prices[j])
            {
                if(j == prices.size()-2)
                    profit += prices[j+1] - prices[i];        //���������ֱ�Ӽ���profit
                j++;
                continue;
            }
            else
            {
                profit += prices[j]-prices[i];
                i = j+1;
                j = j+1;
            }
        }
        return profit;
    }
};
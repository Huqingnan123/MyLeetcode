class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() == 0)
            return 0;
        int minPrice = prices[0];
        int opt = 0; 
        for(int i = 1; i < prices.size(); i++)
        {
            opt = max(opt, prices[i] - minPrice);
            minPrice = min(prices[i], minPrice);
        }
        return opt;
    }
};
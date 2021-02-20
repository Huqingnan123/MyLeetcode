class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if(nums.size() == 0)
            return 0;
        int maxSum = -INT_MAX;
        int curSum = 0;
        for(int num : nums)
        {
            //curSum <= 0 就舍弃前面子数组，curSum变为num的值
            curSum = (curSum <= 0 ? num : curSum + num);
            maxSum = max(maxSum, curSum);
        }
        return maxSum;
    }
};
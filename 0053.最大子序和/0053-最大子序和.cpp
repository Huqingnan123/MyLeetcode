class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if(nums.size() == 0)
            return 0;
        int maxSum = INT_MIN;
        int curSum = 0;
        for(int i = 0; i < nums.size(); i++) {
            curSum = max(nums[i], nums[i] + curSum);
            maxSum = max(maxSum, curSum);
        }
        return maxSum;
    }
};
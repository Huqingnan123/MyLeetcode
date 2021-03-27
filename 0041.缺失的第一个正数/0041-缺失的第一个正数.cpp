class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        // 不在[1,n]范围内的数置换成n+1
        for(int i = 0; i < n; i++) {
            if(nums[i] <= 0 || nums[i] > n) {
                nums[i] = n+1;
            }
        }
        //对于数组中出现过的位于[1,n]之间的pos，将索引pos-1处的nums[pos-1]标记为负数（代表正整数pos出现过）
        for(int i = 0; i < n; i++) {
            int pos = abs(nums[i]);
            if(pos >= 1 && pos <= n) {
                if(nums[pos-1] > 0)
                    nums[pos-1] = -nums[pos-1];
            }
        }
        for(int i = 0; i < n; i++) {
            // nums[i] > 0表示 pos:i+1 从未出现过，所以pos-1处的nums[i]还未被标记为负数
            if(nums[i] > 0)
                return i+1;
        }
        return n+1;
    }
};
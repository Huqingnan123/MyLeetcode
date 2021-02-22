class Solution {
public:
    // 根据题意，数组可以按照以下规则划分为两部分。
    // 左子数组： nums[i] = i；
    // 右子数组： nums[i] != i; 
    // 缺失的数字等于 “右子数组的首位元素” 对应的索引；因此考虑使用二分法查找 “右子数组的首位元素”
    int missingNumber(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;
        while(left <= right)
        {
            int mid = left + (right - left) / 2;
            //缺少的一定在右边区间
            if(nums[mid] == mid)
                left = mid + 1;
            //缺少的一定在左边区间
            else
                right = mid - 1;
        }
        return left;
    }
};
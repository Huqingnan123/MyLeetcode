class Solution {
public:
    // 1、暴力法：遍历计数
    // int search(vector<int>& nums, int target) {
    //     int count = 0;
    //     for(int i = 0; i < nums.size(); i++)
    //         if(nums[i] == target)
    //             count++;
    //     return count;
    // }

    // 2、二分法优化
    // 只要能找出给定的数字 k 在有序数组第一个位置和最后一个位置，就能知道该数字出现的次数。
    int search(vector<int>& nums, int target) {
        return getright(nums, target) - getleft(nums, target) + 1;
    }
    // 二分找第一个位置（左边界）
    int getleft(vector<int>& nums, int target)
    {
        // 找边界的时候是左闭右开区间，[2,3,5,7]时应该是[0,4)
        int left = 0, right = nums.size();
        while(left < right)
        {
            int mid = (right + left)/2;
            if(nums[mid] >= target) 
                right = mid;
            else if(nums[mid] < target) 
                left = mid + 1;
        }
        return left;
    }
    // 二分找最后一个位置（右边界）
    int getright(vector<int>& nums, int target)
    {
        int left = 0, right = nums.size();
        while(left < right)
        {
            int mid = (right + left)/2;
            if(nums[mid] <= target) 
                left = mid + 1;
            else if(nums[mid] > target) 
                right = mid;
        }
        return left - 1;
    }
};
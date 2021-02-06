class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        if(nums.size() <= 1)
            return vector<int>{};
        int left = 0, right = nums.size()-1;
        while(left < right)
        {
            if(nums[left] + nums[right] == target)
                return vector<int> {nums[left],nums[right]};
            else if(nums[left] + nums[right] > target)
                right--;
            else if(nums[left] + nums[right] < target)
                left++;
        }
        return vector<int>{};
    }
};
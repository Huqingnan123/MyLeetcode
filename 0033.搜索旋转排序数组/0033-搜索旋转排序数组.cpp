class Solution {
public:
    int search(vector<int>& nums, int target) {
        if(nums.size() == 0)
            return -1;
        int pos = findPos(nums);
        if(target <= nums[nums.size()-1]) {
            return binarySearch(nums, pos, nums.size()-1, target);
        }
        return binarySearch(nums, 0, pos - 1, target);
    }
    //寻找旋转之前排序数组的起始点（即寻找min值的位置）
    int findPos(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;
        while(left < right) {
            int mid = left + (right - left) / 2;
            if(nums[mid] < nums[right])
                right = mid;
            else if(nums[mid] > nums[right])
                left = mid + 1;
        }
        return left;
    }
    int binarySearch(vector<int>& nums, int left, int right, int target) {
        while(left <= right) {
            int mid = left + (right - left) / 2;
            if(nums[mid] == target)
                return mid;
            else if(nums[mid] > target)
                right = mid - 1;
            else
                left = mid + 1;
        }
        return -1;
    }
};
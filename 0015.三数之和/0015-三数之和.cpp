class Solution {
public:
    vector<vector<int>> threeSum(vector<int> &nums) {
        vector<vector<int>> result;
        if(nums.size() <= 2)
            return result;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size() - 2; i++) {
            //合理剪枝（impossible)
            if(nums[i] > 0)
                break;
            int target = -nums[i];
            int left = i+1, right = nums.size()-1;
            while(left < right) {
                int num1 = nums[left];
                int num2 = nums[right];
                if(nums[left] + nums[right] < target) {
                    while(left < right && nums[left] == num1)
                        left++;
                }
                else if(nums[left] + nums[right] > target) {
                    while(left < right && nums[right] == num2)
                        right--;
                }
                else if(nums[left] + nums[right] == target) {
                    result.push_back({nums[i], nums[left], nums[right]});
                    //双指针同时移动->去重
                    while(left < right && nums[left] == num1)
                        left++;
                    while(left < right && nums[right] == num2)
                        right--;
                }
            }
            //nums[i]去重
            while(i+1 < nums.size() && nums[i+1] == nums[i])
                i++;
        }
        return result;
    }
};
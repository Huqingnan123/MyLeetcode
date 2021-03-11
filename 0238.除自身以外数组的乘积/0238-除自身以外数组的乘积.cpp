class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> result(nums.size());
        for(int i = 0, project = 1; i < nums.size(); project *= nums[i], i++)
            result[i] = project;
        for(int i = nums.size()-1, project = 1; i >= 0; project *= nums[i], i--)
            result[i] *= project;
        return result;
    }
};
class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> result;
		sort(nums.begin(), nums.end());              //先构成最小序排列
        result.emplace_back(nums);
		while (next_permutation(nums.begin(), nums.end())) {   //给出下一个较大排列
			result.emplace_back(nums);
		}
        return result;
    }
};
class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> result;
		sort(nums.begin(), nums.end());              //�ȹ�����С������
        result.emplace_back(nums);
		while (next_permutation(nums.begin(), nums.end())) {   //������һ���ϴ�����
			result.emplace_back(nums);
		}
        return result;
    }
};
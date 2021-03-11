class Solution {
public:
    // 1������stl��next_permutation��������
    // vector<vector<int>> permute(vector<int>& nums) {
    //     vector<vector<int>> result;
    //     sort(nums.begin(),nums.end());
    //     result.emplace_back(nums);
    //     while(next_permutation(nums.begin(),nums.end()))
    //         result.emplace_back(nums);
    //     return result;
    // }

    // 2��dfs���swap���������з���
    vector<vector<int>> result;
    vector<vector<int>> permute(vector<int>& nums) {
        if(nums.size() == 0)
            return {};
        dfs(nums, 0);
        return result;
    }
    void dfs(vector<int>& nums, int depth) {
        if(depth == nums.size()) {
            result.push_back(nums);
            return ;
        }
        //��Ŀ˵�����ظ����֣��ʲ���unordered_setȥ��
        for(int i = depth; i < nums.size(); i++) {
            swap(nums[depth], nums[i]);
            dfs(nums, depth+1);
            swap(nums[depth], nums[i]);
        }
    }
};
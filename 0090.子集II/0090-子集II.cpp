class Solution {
public:
    vector<int> temp;
    vector<vector<int>> res;
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        dfs(0, nums);
        return res;
    }
    void dfs(int depth, vector<int>& nums) {
        if(depth == nums.size()) {
            res.push_back(temp);
            return ;
        }
        temp.push_back(nums[depth]);
        dfs(depth + 1, nums);
        // 去重，避免重复子集
        while(depth < nums.size() && nums[depth] == temp.back())
            depth++;
        temp.pop_back();
        dfs(depth, nums);
    }
};
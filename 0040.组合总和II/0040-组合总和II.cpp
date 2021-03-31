class Solution {
public:
    vector<vector<int>> res;
    vector<int> temp;
    void backtrack(vector<int>& candidates, int pos, int target)
    {
        if(target == 0) {
            res.push_back(temp);
            return;
        }
        if(target < 0 || pos == candidates.size())
            return ;
        temp.push_back(candidates[pos]);
        backtrack(candidates, pos+1, target - candidates[pos]);
        //去重，防止重复选取相同组合
        while(pos < candidates.size() && candidates[pos] == temp.back())
            pos++;
        temp.pop_back();
        backtrack(candidates, pos, target);
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        backtrack(candidates, 0, target);
        return res;
    }
};
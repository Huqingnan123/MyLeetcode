class Solution {
public:
    vector<vector<int>> res;
    vector<int> temp;
    void backtrack(vector<int>& candidates, int pos, int target)
    {
        if(target == 0)
        {
            res.push_back(temp);
            return;
        }
        for(int i = pos; i < candidates.size() && target - candidates[i] >= 0; i++)
        {
            //如果和刚刚pop_back出来的元素相同，向后continue去重
            if(i > pos && candidates[i] == candidates[i-1])
                continue;
            temp.push_back(candidates[i]);
            backtrack(candidates, i+1, target - candidates[i]);
            temp.pop_back();
        }

    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        backtrack(candidates, 0, target);
        return res;
    }
};
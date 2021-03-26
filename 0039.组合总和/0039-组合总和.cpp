class Solution {
public:
    vector<int> vec;
    vector<vector<int>> res;
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        dfs(candidates, 0, 0, target);
        return res;
    }
    void dfs(vector<int>& candidates, int pos, int curSum, int target) {
        if(curSum == target) {
            res.push_back(vec);
            return ;
        }
        if(pos == candidates.size())
            return ;
        // ��ֱ������posλ�õ���
        dfs(candidates, pos+1, curSum, target);
        // ���ظ�ѡ��ǰposλ�õ���(�ظ�dfs)
        if(curSum + candidates[pos] <= target) {
            curSum += candidates[pos];
            vec.push_back(candidates[pos]);
            dfs(candidates, pos, curSum, target);
            curSum -= candidates[pos];
            vec.pop_back();
        }
    }
};
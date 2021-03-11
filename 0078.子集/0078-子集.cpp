class Solution {
public:
    vector<int> temp;
    vector<vector<int>> result;
    vector<vector<int>> subsets(vector<int>& nums) {
        dfs(0, nums);
        return result;
    }
    void dfs(int depth, vector<int>& nums) {
        if(depth == nums.size()) {
            result.push_back(temp);
            return ;
        }
        //����ÿһ��λ�ã�����ѡ���߲�ѡ������ѡ����ɣ����ݣ�
        temp.push_back(nums[depth]);
        dfs(depth+1, nums);
        temp.pop_back();
        dfs(depth+1, nums);
    }
};
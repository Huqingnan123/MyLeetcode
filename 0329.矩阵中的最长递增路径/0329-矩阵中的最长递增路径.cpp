class Solution {
public:
    // 记忆化深度搜索 (常规dfs会超时)
    vector<vector<int>> dp;
    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if(matrix.size() == 0 || matrix[0].size() == 0)
            return 0;    
        int result;
        // 最长递增路径至少为1，初始化为1 (单元格自己的长度)
        dp.assign(matrix.size(), vector<int>(matrix[0].size(), 1));
        // 出发点从(0,0)到(m,n),由于记忆化dp搜索,后面的dfs结果可以使用之前的dp结果计算
        for(int i = 0; i < matrix.size(); i++)
            for(int j = 0; j < matrix[0].size(); j++)
                result = max(result, dfs(matrix, i, j));
        return result;
    }
    int dfs(vector<vector<int>>& matrix, int i, int j) {
        //从(i,j)出发的最长递增路径已经得到
        if(dp[i][j] != 1)
            return dp[i][j];
        for(int d = 0; d < 4; d++) {
            int next_i = i + dx[d];
            int next_j = j + dy[d];
            //若(i,j)上、下、左、右的单元格元素值比(i,j)大，可以根据其已经计算过的 “最长递增路径 + 1” 获取从(i,j)出发的最长递增路径(省去重复dfs)
            if(next_i >= 0 && next_i < matrix.size() && next_j >= 0 && next_j < matrix[0].size() && matrix[next_i][next_j] > matrix[i][j])
                dp[i][j] = max(dp[i][j], dfs(matrix, next_i, next_j) + 1);
        }
        return dp[i][j];
    }
};
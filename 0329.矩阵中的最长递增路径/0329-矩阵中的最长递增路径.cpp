class Solution {
public:
    // ���仯������� (����dfs�ᳬʱ)
    vector<vector<int>> dp;
    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if(matrix.size() == 0 || matrix[0].size() == 0)
            return 0;    
        int result;
        // �����·������Ϊ1����ʼ��Ϊ1 (��Ԫ���Լ��ĳ���)
        dp.assign(matrix.size(), vector<int>(matrix[0].size(), 1));
        // �������(0,0)��(m,n),���ڼ��仯dp����,�����dfs�������ʹ��֮ǰ��dp�������
        for(int i = 0; i < matrix.size(); i++)
            for(int j = 0; j < matrix[0].size(); j++)
                result = max(result, dfs(matrix, i, j));
        return result;
    }
    int dfs(vector<vector<int>>& matrix, int i, int j) {
        //��(i,j)�����������·���Ѿ��õ�
        if(dp[i][j] != 1)
            return dp[i][j];
        for(int d = 0; d < 4; d++) {
            int next_i = i + dx[d];
            int next_j = j + dy[d];
            //��(i,j)�ϡ��¡����ҵĵ�Ԫ��Ԫ��ֵ��(i,j)�󣬿��Ը������Ѿ�������� �������·�� + 1�� ��ȡ��(i,j)�����������·��(ʡȥ�ظ�dfs)
            if(next_i >= 0 && next_i < matrix.size() && next_j >= 0 && next_j < matrix[0].size() && matrix[next_i][next_j] > matrix[i][j])
                dp[i][j] = max(dp[i][j], dfs(matrix, next_i, next_j) + 1);
        }
        return dp[i][j];
    }
};
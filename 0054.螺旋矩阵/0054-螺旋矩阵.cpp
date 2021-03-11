class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if(matrix.size() == 0 || matrix[0].size() == 0)
            return {};
        int dx[4] = {0, 1, 0, -1};
        int dy[4] = {1, 0, -1, 0};
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        vector<int> result;
        int x = 0, y = 0, d = 0;
        for(int i = 0; i < m*n; i++) {
            result.push_back(matrix[x][y]);
            visited[x][y] = true;
            int nextx = x + dx[d];
            int nexty = y + dy[d];
            if(nextx < 0 || nextx >= m || nexty < 0 || nexty >= n || visited[nextx][nexty]) {
                d = (d + 1) % 4;
                nextx = x + dx[d];
                nexty = y + dy[d];
            }
            x = nextx;
            y = nexty;
        }
        return result;
    }
};
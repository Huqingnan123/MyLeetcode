class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> result(n, vector<int>(n, 0));
        //右、下、左、上四个方向循环变化
        int dx[4] = {0, 1, 0, -1};
        int dy[4] = {1, 0, -1, 0};
        vector<vector<bool>> visited(n, vector<bool>(n, false));
        int x = 0, y = 0, d = 0;
        for(int i = 1; i <= n*n; i++) {
            result[x][y] = i;
            visited[x][y] = true;
            int nextx = x + dx[d];
            int nexty = y + dy[d];
            if(nextx < 0 || nextx >= n || nexty < 0 || nexty >= n || visited[nextx][nexty]) {
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
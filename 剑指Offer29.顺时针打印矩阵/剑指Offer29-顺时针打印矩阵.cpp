class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if(matrix.size() == 0 || matrix[0].size() == 0)
            return vector<int> {};
        //����˳ʱ���ӡ�ı�������
        vector<vector<int>> direction {{0,1},{1,0},{0,-1},{-1,0}};
        int m = matrix.size();
        int n = matrix[0].size();
        //���ʱ������
        vector<vector<int>> visited(m,vector<int>(n));
        vector<int> result;
        int x = 0, y = 0, d = 0;
        //һ����m*n������Ҫ������
        for(int i = 0; i < m*n; i++)
        {
            visited[x][y] = 1;
            result.push_back(matrix[x][y]);
            int nextx = x + direction[d][0];
            int nexty = y + direction[d][1];
            //��Ҫ�ı�����һ������
            if(nextx < 0 || nextx >= m || nexty < 0 || nexty >= n || visited[nextx][nexty])
            {
                d = (d+1) % 4;
                nextx = x + direction[d][0];
                nexty = y + direction[d][1];
            }   
            x = nextx;
            y = nexty;
        }
        return result;
    }
};
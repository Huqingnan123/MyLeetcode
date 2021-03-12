class Solution {
public:
    //����Ҫʹ�õ�visited����
    int dx[4] = {0, 1, 0, -1};
    int dy[4] = {1, 0, -1, 0};
    void rotate(vector<vector<int>>& matrix) {
        if(matrix.size() == 0 || matrix.size() == 1)
            return ;
        int n = matrix.size();
        //һȦһȦ�ؽ���˳ʱ���ƶ�
        for(int i = 0; i < n / 2; i++) {
            //��ǰȦ��Ҫ�ƶ��Ĳ���
            for(int j = 0; j < n - 2*i - 1; j++) {
                //��ǰȦԪ������, ÿһ�������(i,i)��ʼ˳��
                int x = i, y = i, d = 0, pre = matrix[x][y], temp = matrix[x][y];
                for(int k = 0; k < 4 * (n - 2*i - 1); k++) {
                    int nextx = x + dx[d];
                    int nexty = y + dy[d];
                    if(nextx < i || nextx >= n - i || nexty < i || nexty >= n - i) {
                        d = (d + 1) % 4;
                        nextx = x + dx[d];
                        nexty = y + dy[d];
                    }
                    temp = matrix[nextx][nexty];
                    matrix[nextx][nexty] = pre;
                    pre = temp;
                    x = nextx;
                    y = nexty;
                }
            }
        }
        return ;
    }
};
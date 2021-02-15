class Solution {
public:
    int movingCount(int m, int n, int k) {
        row = m;
        col = n;
        bfs(0,0,k);
        return count;
    }
private:
    vector<vector<int>> direction{{0,-1},{0,1},{-1,0},{1,0}};
    bool visited[110][110];
    int count = 0;
    int row, col;
    //计算坐标数位之和
    int digitSum(int number1, int number2) {
        int result = 0;
        while(number1 != 0 || number2 != 0)
        {
            result += number1 % 10;
            result += number2 % 10;
            number1 /= 10;
            number2 /= 10;
        }
        return result;
    }
    //BFS进行遍历搜索
    void bfs(int m, int n, int k) {
        if(m < 0 || m >= row || n < 0 || n >= col || digitSum(m,n) > k || visited[m][n])
            return ;
        visited[m][n] = true;
        count++;
        for(auto next : direction)
            bfs(m + next[0], n + next[1], k);
        return ;
    }
};
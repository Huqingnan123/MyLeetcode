class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        rows = board.size();
        cols = board[0].size();
        //任意格子都可以作为起始点
        for(int i = 0; i < rows; i++)
            for(int j = 0; j < cols; j++)
                if(board[i][j] == word[0] && backTracking(board, word, 0, i, j))
                    return true;
        return false;
    }
private:
    vector<vector<int>> direction{{0,-1},{0,1},{-1,0},{1,0}};
    bool visited[210][210];
    int rows, cols;
    bool backTracking(vector<vector<char>>& board, string word, int level, int row, int col) {
        if(level == word.size())
            return true;
        if(row < 0 || row >= rows || col < 0 || col >= cols || 
        board[row][col] != word[level] || visited[row][col])
            return false;
        visited[row][col] = true;
        //左，右，上，下四种方向
        for(auto next : direction)
            if(backTracking(board, word, level+1, row+next[0], col+next[1]))
                return true;
        visited[row][col] = false;
        return false;
    }
};
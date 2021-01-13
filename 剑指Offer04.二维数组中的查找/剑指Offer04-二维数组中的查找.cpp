class Solution {
public:
    
    bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
        if (matrix.size() == 0 || matrix[0].size() == 0)
            return false;
        // 从右上角开始向左下角缩小查找区间 (row++ 或者 col--)
        int row = 0;
        int col = matrix[0].size() - 1; 
        while (row <= matrix.size()-1 && col >= 0) 
        {
            if (target == matrix[row][col])
                return true;
            else if (target > matrix[row][col])
                row++;
            else if (target < matrix[row][col])
                col--;
        }
        return false;
    }
};
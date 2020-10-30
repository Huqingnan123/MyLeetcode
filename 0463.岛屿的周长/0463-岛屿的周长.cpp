class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        if (grid.empty()) 
            return 0;
        int n = grid.size();            
        int m = grid[0].size();              //网格的长和宽
        int lands = 0;
        int boarder = 0;                     //land表示岛屿有多少格子，boarder表示格子之间的相接边,最终周长为4*lands - 2*boarder
        int bias[2][2] = {{-1, 0}, {0, -1}}; 
        for (int i = 0; i < n; ++i) 
        {
            for (int j = 0; j < m; ++j) 
            {
                if (grid[i][j] == 0) 
                    continue;
                else
                {
                    //找到一块土地
                    lands++;
                    //向上面或者左边偏移一格，寻找相接边
                    for (int k = 0; k < 2; ++k) 
                    {
                        int x = i + bias[k][0];
                        int y = j + bias[k][1];
                        if (x < 0 || y < 0) 
                            continue;
                        if (grid[x][y] == 1)
                            boarder++;
                    }
                }
            }
        }
        return 4*lands - 2*boarder;        //每一条相接边减少两条边
    }
};
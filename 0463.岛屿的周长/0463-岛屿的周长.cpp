class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        if (grid.empty()) 
            return 0;
        int n = grid.size();            
        int m = grid[0].size();              //����ĳ��Ϳ�
        int lands = 0;
        int boarder = 0;                     //land��ʾ�����ж��ٸ��ӣ�boarder��ʾ����֮�����ӱ�,�����ܳ�Ϊ4*lands - 2*boarder
        int bias[2][2] = {{-1, 0}, {0, -1}}; 
        for (int i = 0; i < n; ++i) 
        {
            for (int j = 0; j < m; ++j) 
            {
                if (grid[i][j] == 0) 
                    continue;
                else
                {
                    //�ҵ�һ������
                    lands++;
                    //������������ƫ��һ��Ѱ����ӱ�
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
        return 4*lands - 2*boarder;        //ÿһ����ӱ߼���������
    }
};
class Solution {
public:
    // 最小移动次数、最短变化路径之类的题都可转化为 BFS 进行求解最短变化路径
    // 将 2x3 的二维int数组转化成一维字符串string（状态转化），需要从”初始字符串“变化到达“123450”。
    int slidingPuzzle(vector<vector<int>>& board) {
        string start = "";
        string target = "123450";

        //将board谜板转化为一维字符串start
        for (int i = 0; i < 2; i++) 
            for (int j = 0; j < 3; j++) 
                start.push_back(board[i][j] + '0');
  
        // 记录一维字符串的相邻索引
        vector<vector<int>> neighbor = {
            { 1, 3 },
            { 0, 2, 4 },
            { 1, 5 },
            { 0, 4 },
            { 1, 3, 5 },
            { 2, 4 }
        };
        
        queue<string> q;
        unordered_set<string> visited;   
        q.push(start);
        visited.insert(start);
        
        int step = 0;
        while (!q.empty()) 
        {
            //number 是这一层的 string 状态数量
            int number = q.size();
            for (int i = 0; i < number; i++) 
            {
                string current = q.front(); 
                q.pop();
                // 判断是否达到目标局面
                if (target == current) 
                    return step;
                // 找到数字0在一维string中的索引值
                int index = 0;
                while(current[index] != '0')
                    index++;
                // 在逻辑二维谜板上将数字0与相邻位置的数字交换位置
                for (auto adjacent : neighbor[index]) 
                {
                    string newStatus = current;
                    swap(newStatus[adjacent], newStatus[index]);
                    // 防止走回头路，未出现过的状态才加入queue
                    if (visited.find(newStatus) == visited.end()) 
                    {
                        q.push(newStatus);
                        visited.insert(newStatus);
                    }
                }
            }
            step++;
        }
        return -1;
    }
};
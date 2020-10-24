class Solution {
public:
    int videoStitching(vector<vector<int>>& clips, int T) {
        vector<vector<int>> find_table;       //用于保存各个结点值存在于哪些片段index中
        vector<int> clip_index;
        for(int i = 0; i <= T; i++)
        {
            clip_index.clear();
            for(int j = 0; j < clips.size(); j++)
            {
                //如果i点处于clip[j]片段中，加入clip_index (" 左开右闭 ")
                if(i > clips[j][0] && i <= clips[j][1]) 
                    clip_index.push_back(j);
            }
            find_table.push_back(clip_index);            //初始数据结构存储完成,find_table
        }
        vector<int> result(T+1,0);                      //result[i]表示0-i需要的最小片段数
        int minmum;
        for(int i = 1; i <= T; i++)
        {
            minmum = INT_MAX;
            for(auto& index : find_table[i])                 //find_table[i]是包含i的片段index
            {
                minmum = min(minmum, result[clips[index][0]]);//可以到i处的前驱端点的result最小值
            }
            if(minmum == INT_MAX)                       //说明中间存在断点，结点i不存在于任何clip中
                return -1;
            result[i] = minmum + 1;                          //前驱端点minmum到i只需要再加一段
        }
        return result[T];
    }
};
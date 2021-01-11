class Solution {
public:
    //并查集进行索引分块block即可（同处一个区域块中的索引都可以互换字符）
    //关键在于merge和find_father函数的实现
    int union_Set[100000];
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        //初始化并查集
        for(int i = 0; i < s.size(); i++)
            union_Set[i] = i;
        //处理所给索引数据
        for(auto p : pairs)
            merge(p[0],p[1]);
        vector<vector<int>> BlockResult(s.size());
        //将彼此联通的索引集中在一个vector中
        for(int i = 0; i < s.size(); i++)
            BlockResult[find_father(i)].push_back(i);
        for(int i = 0; i < s.size(); i++)
        {
            if(BlockResult[i].size() <= 1)
                continue;
            //联通索引块内部的局部字典排序
            string tempSort(BlockResult[i].size(),'0');
            //把联通索引内部按从小到大排序
            sort(BlockResult[i].begin(),BlockResult[i].end());
            for(int j = 0; j < BlockResult[i].size(); j++)
                tempSort[j] = s[BlockResult[i][j]];
            sort(tempSort.begin(),tempSort.end());
            for(int j = 0; j < BlockResult[i].size(); j++)
                s[BlockResult[i][j]] = tempSort[j];
        }
        return s;
    }
    int find_father(int v){
        if(union_Set[v] != v)
            union_Set[v] = find_father(union_Set[v]);
        return union_Set[v];
    }
    void merge(int v1, int v2){
        int father1 = find_father(v1);
        int father2 = find_father(v2);
        if(father1 != father2)
            union_Set[father2] = father1;
    }
};
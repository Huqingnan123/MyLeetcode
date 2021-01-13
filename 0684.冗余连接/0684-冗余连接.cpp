class Solution {
public:
    //简单的并查集操作模板，find_father函数以及merge函数的实现，遇到环就可以直接返回冗余连接
    int UnionSet[1001]{0};
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        for(auto& edge : edges)
        {
            if(UnionSet[edge[0]] == 0)
                UnionSet[edge[0]] = edge[0];
            if(UnionSet[edge[1]] == 0)
                UnionSet[edge[1]] = edge[1];
            if(merge(edge[0],edge[1]))
                continue;
            else
                return vector<int>{edge[0],edge[1]};
        }
        return vector<int>{};
    }
    int find_father(int v){
        if(UnionSet[v] != v)
            UnionSet[v] = find_father(UnionSet[v]);
        return UnionSet[v];
    }
    bool merge(int v1, int v2){
        int father1 = find_father(v1);
        int father2 = find_father(v2);
        if(father1 != father2)
        {
            UnionSet[father2] = father1;
            return true;
        }
        else
            return false;
    }
};
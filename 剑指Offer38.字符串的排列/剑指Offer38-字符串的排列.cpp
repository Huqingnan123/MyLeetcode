class Solution {
public:
    //1、可以直接采用sort之后next_permutation一直生成下一个排列

    //2、不采用stl中的函数，可以采用dfs回溯算法，此题思路同全排列Ⅰ，Ⅱ题（46，47题）
    vector<string> permutation(string s) {
        vector<string> result;
        dfs(s, result, 0);
        return result;
    }
    void dfs(string& s, vector<string>& result, int depth) {
        if(depth == s.size())
        {
            result.push_back(s);
            return ;
        }
        //记录当前depth之下已经交换位置的字符，防止重复替换相同字符至depth位置
        unordered_set<char> used;
        //当前起点depth,可以与之后字符一一交换位置（防止去重）
        for(int i = depth; i < s.size(); i++)
        {
            if(used.find(s[i]) != used.end())
                continue;
            used.insert(s[i]);
            swap(s[depth], s[i]);
            dfs(s, result, depth+1);
            //回溯撤销操作
            swap(s[depth], s[i]);
        }
    }
};
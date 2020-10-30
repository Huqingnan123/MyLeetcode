class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string result;
        if(strs.empty())                         //strs空，直接返回
            return result;
        for(int i = 0; i<strs[0].size(); i++)    //以第一个字符串的字符作为比较标准，一直后移
        {  
            for(int j = 1; j<strs.size(); j++)   
            {
                if(strs[j][i] == strs[0][i])
                    continue;
                else
                    return result;
            }
            result.push_back(strs[0][i]);       //当且仅当所有字符串该位置上的字符都一致，push_back
        }
        return result;
    }
};
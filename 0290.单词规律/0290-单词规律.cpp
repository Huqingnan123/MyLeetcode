class Solution {
public:
    bool wordPattern(string pattern, string s) {
        vector<string> vec;
        int start = 0;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == ' ')
            {
                vec.push_back(s.substr(start, i - start));
                start = i + 1;
            }
        }
        vec.push_back(s.substr(start, s.size() - start));    //根据空格位置划分单词vec
        if(vec.size() != pattern.size())
            return false;
        unordered_map<char, string> mp;
        unordered_set<string> used_str;                      //防止单词重复对应pattern
        for (int i = 0; i < pattern.size(); i++)
        {
            if (mp.find(pattern[i]) == mp.end())
            {
                if(used_str.find(vec[i]) != used_str.end())   //同一个单词不能和多个pattern（a或b)对应
                    return false;
                else                                          //不重复的情形下构建新的<char,string>键值对
                {
                    mp[pattern[i]] = vec[i];
                    used_str.insert(vec[i]);
                }
            }
            else                                              //已存在的键，直接比较值是否匹配
                if (mp[pattern[i]] != vec[i])
                    return false;
        }
        return true;
    }
};
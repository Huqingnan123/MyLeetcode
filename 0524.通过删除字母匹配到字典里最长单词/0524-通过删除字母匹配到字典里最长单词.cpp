class Solution {
public:
    // 转化为判断“是否是子序列”的问题
    string findLongestWord(string s, vector<string>& dictionary) {
        string result = "";
        for(auto t : dictionary)
        {
            if(isSubstr(s, t))
            {
                // 要么t比result更长, 要么二者长度相同且t的字典序更小，t才替换result
                if(t.size() > result.size())
                    result = t;
                else if(t.size() == result.size() && t < result)
                    result = t;
            }
        }
        return result;
    }
    // 用于判断字符串t是否是s的子序列 （双指针判断子序列!!!)
    bool isSubstr(string& s, string& t) {
        if(t.size() > s.size())
            return false;
        int i = 0, j = 0;
        while(i < s.size() && j < t.size())
        {
            // 成功匹配字符
            if(s[i] == t[j])
                j++;
            i++;
        }
        return j == t.size() ? true : false;
    }
};
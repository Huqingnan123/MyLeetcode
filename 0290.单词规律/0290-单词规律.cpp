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
        vec.push_back(s.substr(start, s.size() - start));    //���ݿո�λ�û��ֵ���vec
        if(vec.size() != pattern.size())
            return false;
        unordered_map<char, string> mp;
        unordered_set<string> used_str;                      //��ֹ�����ظ���Ӧpattern
        for (int i = 0; i < pattern.size(); i++)
        {
            if (mp.find(pattern[i]) == mp.end())
            {
                if(used_str.find(vec[i]) != used_str.end())   //ͬһ�����ʲ��ܺͶ��pattern��a��b)��Ӧ
                    return false;
                else                                          //���ظ��������¹����µ�<char,string>��ֵ��
                {
                    mp[pattern[i]] = vec[i];
                    used_str.insert(vec[i]);
                }
            }
            else                                              //�Ѵ��ڵļ���ֱ�ӱȽ�ֵ�Ƿ�ƥ��
                if (mp[pattern[i]] != vec[i])
                    return false;
        }
        return true;
    }
};
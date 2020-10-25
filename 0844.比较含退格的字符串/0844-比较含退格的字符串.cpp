class Solution {
public:
    bool backspaceCompare(string S, string T) {
        string s;
        string t;          //string模拟栈
        for(auto& ch : S)
        {
            if(ch == '#' && !s.empty())
                s.pop_back();
            else if(ch != '#')
                s.push_back(ch);
        }
        for(auto& ch : T)
        {
            if(ch == '#' && !t.empty())
                t.pop_back();
            else if(ch != '#')
                t.push_back(ch);
        }
        return s == t ? true : false;
    }
};
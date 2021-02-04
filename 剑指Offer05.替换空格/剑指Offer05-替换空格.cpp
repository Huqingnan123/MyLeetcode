class Solution {
public:
    string replaceSpace(string s) {
        string result;
        for(int i = 0; i < s.size(); i++)
        {
            if(s[i] != ' ')
                result += s[i];
            else
                result += "%20";
        }
        return result;
    }
};
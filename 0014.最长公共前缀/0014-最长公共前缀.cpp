class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size() == 0)
            return "";
        string result;
        string pattern = strs[0];
        for(int i = 0; i < pattern.size(); i++) {
            for(int j = 1; j < strs.size(); j++) {
                if(i >= strs[j].size() || strs[j][i] != pattern[i])
                    return result;
            }
            result += pattern[i];
        }
        return result;
    }
};
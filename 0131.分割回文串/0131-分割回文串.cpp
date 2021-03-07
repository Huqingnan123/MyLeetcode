class Solution {
private:
    vector<vector<int>> dp;
    vector<vector<string>> result;
    vector<string> temp;

public:
    // dfs + 回溯 + dp
    void dfs(string& s, int i) {
        if (i == s.size()) {
            result.push_back(temp);
            return ;
        }
        for (int j = i; j < s.size(); j++) {
            if (isPalindrome(s, i, j) == 1) {
                temp.push_back(s.substr(i, j - i + 1));
                dfs(s, j + 1);
                temp.pop_back();
            }
        }
    }

    // 记忆化搜索中，f[i][j] = 0 表示未搜索，1 表示是回文串，-1 表示不是回文串
    int isPalindrome(string& s, int i, int j) {
        if (dp[i][j] == 1) 
            return 1;
        if (i >= j) 
            return dp[i][j] = 1;
        return dp[i][j] = (s[i] == s[j]) ? isPalindrome(s, i + 1, j - 1) : -1;
    }

    vector<vector<string>> partition(string s) {
        dp.assign(s.size(), vector<int>(s.size()));
        dfs(s, 0);
        return result;
    }
};
class Solution {
public:
    vector<string> result;
    vector<string> generateParenthesis(int n) {
        dfs("", 0, 0, n);
        return result;
    }
    void dfs(string temp, int num1, int num2, int n) {
        if(num1 < num2 || num1 > n)
            return ;
        if(num1 + num2 == n * 2) {
            result.push_back(temp);
            return ;
        }
        
        temp.push_back('(');
        dfs(temp, num1+1, num2, n);
        temp.pop_back();

        temp.push_back(')');
        dfs(temp, num1, num2+1, n);
        temp.pop_back();
    }
};
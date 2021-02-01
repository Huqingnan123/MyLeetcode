class Solution {
public:
     string reverseParentheses(string s) {
        //利用了栈来匹配括号，由内向外逐层反转
        //答案存储在result中，result中一直不含括号
        vector<int> St;
        string result;
        for (int i = 0; i < s.length(); ++i) {
            if (s[i] == '(')
                St.push_back(result.length());
            //匹配一对括号就进行一次反转
            else if (s[i] == ')') 
            {
                int j = St.back();
                St.pop_back();
                reverse(result.begin() + j, result.end());
            } 
            else 
                result += s[i];
        }
        return result;
    }
};
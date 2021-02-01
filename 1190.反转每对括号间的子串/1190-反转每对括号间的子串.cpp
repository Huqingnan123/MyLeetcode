class Solution {
public:
    // - Solution 1: Using Stack to find pair bracket(duplicate reverse) 
    // string reverseParentheses(string s) {
    //     //利用了栈来匹配括号，由内向外逐层反转
    //     //答案存储在result中，result中一直不含括号
    //     vector<int> St;
    //     string result;
    //     for (int i = 0; i < s.length(); ++i) {
    //         if (s[i] == '(')
    //             St.push_back(result.length());
    //         //匹配一对括号就进行一次反转
    //         else if (s[i] == ')') 
    //         {
    //             int j = St.back();
    //             St.pop_back();
    //             reverse(result.begin() + j, result.end());
    //         } 
    //         else 
    //             result += s[i];
    //     }
    //     return result;
    // }
                
    // - Solution 2: Wormholes methods to traverse in different directions(No duplicate)
    string reverseParentheses(string s) {
        int n = s.length();
        vector<int> St;
        vector<int> pair(n);
        //先去找出每一对匹配的括号(存储索引)
        for (int i = 0; i < n; ++i) {
            if (s[i] == '(')
                St.push_back(i);
            if (s[i] == ')') {
                int j = St.back();
                St.pop_back();
                pair[i] = j;
                pair[j] = i;
            }
        }
        string result;
        //i是当前位置,d是方向,1就是向右traverse->
        for (int i = 0, d = 1; i < n; i += d) {
            // 如果碰到括号，那么跳转索引到他对应的括号处，并且将traverse方向置反
            if (s[i] == '(' || s[i] == ')')
            {
                i = pair[i];
                d = -d;
            }
            else
                result += s[i];
        }
        return result;
    }
};
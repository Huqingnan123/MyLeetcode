class Solution {
public:
    bool isValid(string str) {
        stack<char> s;  
        for(auto ch : str) {
            if(ch == '(' || ch == '{' || ch == '[')
                s.push(ch);
            else if(ch == ')') {
                if(s.empty() || s.top() != '(')
                    return false;
                s.pop();
            }
            else if(ch == '}') {
                if(s.empty() || s.top() != '{')
                    return false;
                s.pop();
            }
            else if(ch == ']') {
                if(s.empty() || s.top() != '[')
                    return false;
                s.pop();
            }
        }
        return s.empty();
    }
};
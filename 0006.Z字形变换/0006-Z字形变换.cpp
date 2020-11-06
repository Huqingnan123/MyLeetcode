class Solution {
public:
    string convert(string s, int numRows) {
        if(s.size() <= numRows || numRows == 1)
            return s;
        string result;
        vector<string> my_string(numRows);    //按行构建每一行的字符串
        bool down = false;
        for(int i = 0, rows = 0; i<s.size(); i++)
        {
            my_string[rows] += s[i];
            if(rows == 0 || rows == numRows - 1)
                down = !down;                 //行号---移动方向反向
            rows += down ? 1 : -1;  
        }
        for(auto& str : my_string)            //将numRows-1行拼接
            result += str;
        return result;
    }
};
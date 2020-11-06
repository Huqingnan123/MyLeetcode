class Solution {
public:
    string convert(string s, int numRows) {
        if(s.size() <= numRows || numRows == 1)
            return s;
        string result;
        vector<string> my_string(numRows);    //���й���ÿһ�е��ַ���
        bool down = false;
        for(int i = 0, rows = 0; i<s.size(); i++)
        {
            my_string[rows] += s[i];
            if(rows == 0 || rows == numRows - 1)
                down = !down;                 //�к�---�ƶ�������
            rows += down ? 1 : -1;  
        }
        for(auto& str : my_string)            //��numRows-1��ƴ��
            result += str;
        return result;
    }
};
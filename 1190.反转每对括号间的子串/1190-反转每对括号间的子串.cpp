class Solution {
public:
     string reverseParentheses(string s) {
        //������ջ��ƥ�����ţ�����������㷴ת
        //�𰸴洢��result�У�result��һֱ��������
        vector<int> St;
        string result;
        for (int i = 0; i < s.length(); ++i) {
            if (s[i] == '(')
                St.push_back(result.length());
            //ƥ��һ�����žͽ���һ�η�ת
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
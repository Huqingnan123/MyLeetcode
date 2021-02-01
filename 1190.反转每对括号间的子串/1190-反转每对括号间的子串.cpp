class Solution {
public:
    // - Solution 1: Using Stack to find pair bracket(duplicate reverse) 
    // string reverseParentheses(string s) {
    //     //������ջ��ƥ�����ţ�����������㷴ת
    //     //�𰸴洢��result�У�result��һֱ��������
    //     vector<int> St;
    //     string result;
    //     for (int i = 0; i < s.length(); ++i) {
    //         if (s[i] == '(')
    //             St.push_back(result.length());
    //         //ƥ��һ�����žͽ���һ�η�ת
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
        //��ȥ�ҳ�ÿһ��ƥ�������(�洢����)
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
        //i�ǵ�ǰλ��,d�Ƿ���,1��������traverse->
        for (int i = 0, d = 1; i < n; i += d) {
            // ����������ţ���ô��ת����������Ӧ�����Ŵ������ҽ�traverse�����÷�
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
class Solution {
public:
    // ת��Ϊ�жϡ��Ƿ��������С�������
    string findLongestWord(string s, vector<string>& dictionary) {
        string result = "";
        for(auto t : dictionary)
        {
            if(isSubstr(s, t))
            {
                // Ҫôt��result����, Ҫô���߳�����ͬ��t���ֵ����С��t���滻result
                if(t.size() > result.size())
                    result = t;
                else if(t.size() == result.size() && t < result)
                    result = t;
            }
        }
        return result;
    }
    // �����ж��ַ���t�Ƿ���s�������� ��˫ָ���ж�������!!!)
    bool isSubstr(string& s, string& t) {
        if(t.size() > s.size())
            return false;
        int i = 0, j = 0;
        while(i < s.size() && j < t.size())
        {
            // �ɹ�ƥ���ַ�
            if(s[i] == t[j])
                j++;
            i++;
        }
        return j == t.size() ? true : false;
    }
};
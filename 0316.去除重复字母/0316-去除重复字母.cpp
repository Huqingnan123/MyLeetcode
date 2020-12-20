class Solution {
public:
    //����ջ��̰��˼��
    string removeDuplicateLetters(string s) {
        if(s.size() == 0)
            return "";
        stack<char> stk;
        int LastIndex[26]{-1};     //��¼ÿһ����ĸ���ֵ�����±꣬��Ϊpop�ַ��ıȽ�����
        bool InStack[26]{0};       //��¼��ǰ�ַ��Ƿ�����ջ��
        for(int i = 0; i < s.size(); i++)
            LastIndex[s[i] - 'a'] = i;
        stk.push(s[0]);
        InStack[s[0] - 'a'] = 1;
        for(int i = 1; i < s.size(); i++)
        {
            if(InStack[s[i] - 'a'])
                continue;
            if(s[i] > stk.top())       //����ѹջ������bool���
            {
                stk.push(s[i]);
                InStack[s[i] - 'a'] = 1;
            }  
            else if(s[i] < stk.top())  //�ֵ�����ʱ���ж��Ƿ���popĩβ�ַ�ά�ֵ���ջ                        
            {
                while(!stk.empty() && s[i] < stk.top() && LastIndex[stk.top() - 'a'] > i)
                {
                    InStack[stk.top() - 'a'] = 0;  //pop����ʱ����bool���
                    stk.pop();
                }
                stk.push(s[i]);
                InStack[s[i] - 'a'] = 1; //ѹջ������bool���
            }
        }
        string result;
        while(!stk.empty())
        {
            result.insert(0,1,stk.top());
            stk.pop();
        }
        return result;
    }
};
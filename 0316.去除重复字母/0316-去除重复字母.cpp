class Solution {
public:
    //单调栈，贪心思想
    string removeDuplicateLetters(string s) {
        if(s.size() == 0)
            return "";
        stack<char> stk;
        int LastIndex[26]{-1};     //记录每一个字母出现的最后下标，作为pop字符的比较依据
        bool InStack[26]{0};       //记录当前字符是否已在栈中
        for(int i = 0; i < s.size(); i++)
            LastIndex[s[i] - 'a'] = i;
        stk.push(s[0]);
        InStack[s[0] - 'a'] = 1;
        for(int i = 1; i < s.size(); i++)
        {
            if(InStack[s[i] - 'a'])
                continue;
            if(s[i] > stk.top())       //正常压栈并更新bool标记
            {
                stk.push(s[i]);
                InStack[s[i] - 'a'] = 1;
            }  
            else if(s[i] < stk.top())  //字典逆序时，判断是否能pop末尾字符维持单调栈                        
            {
                while(!stk.empty() && s[i] < stk.top() && LastIndex[stk.top() - 'a'] > i)
                {
                    InStack[stk.top() - 'a'] = 0;  //pop弹出时更新bool标记
                    stk.pop();
                }
                stk.push(s[i]);
                InStack[s[i] - 'a'] = 1; //压栈并更新bool标记
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
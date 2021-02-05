class Solution {
public:
    //����ջ����ģ�⡰pushed����ѹջ���͡�popped���г�ջ������
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> MyStack;
        for(int pushIndex = 0, popIndex = 0; pushIndex < pushed.size(); pushIndex++)
        {
            MyStack.push(pushed[pushIndex]);
            while(!MyStack.empty() && popIndex < popped.size() && MyStack.top() == popped[popIndex])
            {
                MyStack.pop();
                popIndex++;
            }
        }
        //���δ�ܵ��ɿ�ջ��˵�����в�����
        return MyStack.empty();
    }    
};
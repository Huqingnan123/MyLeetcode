class Solution {
public:
    //采用栈进行模拟“pushed序列压栈”和“popped序列出栈”操作
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
        //如果未能弹成空栈，说明序列不符合
        return MyStack.empty();
    }    
};
class MinStack {
public:
    /** initialize your data structure here. */
    stack<int> myStack;
    stack<int> minStack;

    MinStack() {

    }
    
    //����minStackջ��һֱ���ǵ�ǰ����ջ�е���СԪ��
    //��������ջmyStack��minStack�е�Ԫ�ظ���һֱ����ȵ�
    void push(int x) {
        myStack.push(x);
        if(minStack.empty())
            minStack.push(x);
        else
            minStack.push(std::min(minStack.top(), x));
    }
    
    void pop() {
        myStack.pop();
        minStack.pop();
    }
    
    int top() {
        return myStack.top();
    }
    
    int min() {
        return minStack.top();
    }
};

/**
 * Your minStack object will be instantiated and called as such:
 * minStack* obj = new minStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->min();
 */
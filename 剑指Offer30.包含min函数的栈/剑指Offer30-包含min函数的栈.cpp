class MinStack {
public:
    /** initialize your data structure here. */
    stack<int> myStack;
    stack<int> minStack;

    MinStack() {

    }
    
    //保持minStack栈顶一直都是当前数据栈中的最小元素
    //并且两个栈myStack和minStack中的元素个数一直是相等的
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
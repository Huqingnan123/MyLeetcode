class MaxQueue {
    // q是一个普通队列queue，存储所有push进入的元素
    // d是一个单调递减的deque（遇到非递减就pop_back()直至符合递减)
    queue<int> q;
    deque<int> d;
public:
    MaxQueue() {

    }
    
    // 维持d.front()始终是max值
    int max_value() {
        if (d.empty())
            return -1;
        return d.front();
    }
    
    void push_back(int value) {
        //当d的尾部要比即将插入的value小的时候，除去尾部的值
        while (!d.empty() && d.back() < value)
            d.pop_back();
        d.push_back(value);
        q.push(value);
    }
    
    int pop_front() {
        if (q.empty())
            return -1;
        int result = q.front();
        //如果pop_front出了队列max值，将deque.front()也pop出来进行更新
        if (result == d.front()) {
            d.pop_front();
        }
        q.pop();
        return result;
    }
};

/**
 * Your MaxQueue object will be instantiated and called as such:
 * MaxQueue* obj = new MaxQueue();
 * int param_1 = obj->max_value();
 * obj->push_back(value);
 * int param_3 = obj->pop_front();
 */
class MaxQueue {
    // q��һ����ͨ����queue���洢����push�����Ԫ��
    // d��һ�������ݼ���deque�������ǵݼ���pop_back()ֱ�����ϵݼ�)
    queue<int> q;
    deque<int> d;
public:
    MaxQueue() {

    }
    
    // ά��d.front()ʼ����maxֵ
    int max_value() {
        if (d.empty())
            return -1;
        return d.front();
    }
    
    void push_back(int value) {
        //��d��β��Ҫ�ȼ��������valueС��ʱ�򣬳�ȥβ����ֵ
        while (!d.empty() && d.back() < value)
            d.pop_back();
        d.push_back(value);
        q.push(value);
    }
    
    int pop_front() {
        if (q.empty())
            return -1;
        int result = q.front();
        //���pop_front���˶���maxֵ����deque.front()Ҳpop�������и���
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
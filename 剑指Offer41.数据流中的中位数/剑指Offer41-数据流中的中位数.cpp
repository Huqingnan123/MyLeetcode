class MedianFinder {
public:
    /** initialize your data structure here. */
    /* 采用一个大顶堆(左)和一个小顶堆(右)各存储一半数据, 并且维持右半边元素都大于左半边元素 */
    /* 最终中位数就直接从left.top()和right.top()中可以获得*/
    priority_queue<int, vector<int>, less<int> > left;
    priority_queue<int, vector<int>, greater<int> > right;
    int count = 0;

    MedianFinder() {

    }
    void addNum(int num) {
        //加上num至左边大顶堆中或者右边小顶堆中, 维持数量均衡与左右大小关系（优先右边）
        //此时右边的数据个数比左边多一个，num先加入右边，再选出小顶堆中最小的一个移至左边
        if(count % 2)
        {
            right.push(num);
            left.push(right.top());
            right.pop();
        }
        //此时右边的数据个数与左边一样多，num先加入左边，再选出大顶堆中最大的一个移至右边
        else
        {
            left.push(num);
            right.push(left.top());
            left.pop();
        }
        count++;
    }
    
    double findMedian() {
        if(count % 2)
            return right.top();
        else   
            return (double)(left.top() + right.top()) / 2;    
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
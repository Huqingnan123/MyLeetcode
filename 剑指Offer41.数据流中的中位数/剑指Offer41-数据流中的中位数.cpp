class MedianFinder {
public:
    /** initialize your data structure here. */
    /* ����һ���󶥶�(��)��һ��С����(��)���洢һ������, ����ά���Ұ��Ԫ�ض���������Ԫ�� */
    /* ������λ����ֱ�Ӵ�left.top()��right.top()�п��Ի��*/
    priority_queue<int, vector<int>, less<int> > left;
    priority_queue<int, vector<int>, greater<int> > right;
    int count = 0;

    MedianFinder() {

    }
    void addNum(int num) {
        //����num����ߴ󶥶��л����ұ�С������, ά���������������Ҵ�С��ϵ�������ұߣ�
        //��ʱ�ұߵ����ݸ�������߶�һ����num�ȼ����ұߣ���ѡ��С��������С��һ���������
        if(count % 2)
        {
            right.push(num);
            left.push(right.top());
            right.pop();
        }
        //��ʱ�ұߵ����ݸ��������һ���࣬num�ȼ�����ߣ���ѡ���󶥶�������һ�������ұ�
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
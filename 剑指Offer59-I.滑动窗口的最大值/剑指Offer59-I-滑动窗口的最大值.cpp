class Solution {
public:
    // 1�����������ÿһ��SlideWindow�����ֵ
    // vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    //     if(nums.size() == 0)
    //         return vector<int>{};
    //     vector<int> result;
    //     for(int start = 0, end = k; end <= nums.size(); start++, end++)
    //     {
    //         int maxNum = -INT_MAX;
    //         for(int j = start; j < end; j++)
    //             maxNum = max(maxNum, nums[j]);
    //         result.push_back(maxNum);
    //     }
    //     return result;
    // }

    // 2������ ���������С����Լ���dequeά��һ���������� --> �����ٻ�ȡ�����ڵ����ֵ
    // ��̬ά��һ��˫�˶��У��ö��е�ͷ����front()��ʼ���ǵ�ǰ�������ڵ����ֵ��"����"
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        if (nums.size() == 0) 
            return vector<int>{};
        vector<int> result;
        deque<int> Myqueue;
        for (int i = 0; i < nums.size(); i++) 
        {
            // ����½����� nums[i] ���ڵ��ڻ������ڵ�β��Ԫ�أ�
            // ˵����β��Ԫ�ؿ϶��������κλ������ڵ����Ԫ�ء�
            // ������ѭ����̭������С�ڵ���(<=)��Ԫ�ص�β��Ԫ�ء�
            while (!Myqueue.empty() && nums[i] >= nums[Myqueue.back()])
                Myqueue.pop_back();

            // ��Ȼ Myqueue ��ͷ��������Ԫ�ص����������������ǰ���������Ѳ���������������ô��Ҫ����
            // Myqueue�д洢���������������жϵ�ǰfront���ֵ�����뵱ǰi֮���Ƿ񳬹����ھ��룬update
            if (!Myqueue.empty() && i - Myqueue.front() >= k) 
                Myqueue.pop_front();

            Myqueue.push_back(i);

            //i�ﵽk-1֮��ÿһ�ִ��ڶ�Ҫpush��ȥһ��maxֵ
            if (i >= k-1) 
                result.push_back(nums[Myqueue.front()]);
        }
        return result;
    }
};
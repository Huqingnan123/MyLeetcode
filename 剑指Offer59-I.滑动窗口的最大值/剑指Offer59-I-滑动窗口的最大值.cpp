class Solution {
public:
    // 1、暴力法求解每一个SlideWindow的最大值
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

    // 2、采用 “单调队列”，自己用deque维护一个单调队列 --> 来快速获取窗口内的最大值
    // 动态维护一个双端队列，让队列的头部（front()）始终是当前滑动窗口的最大值的"索引"
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        if (nums.size() == 0) 
            return vector<int>{};
        vector<int> result;
        deque<int> Myqueue;
        for (int i = 0; i < nums.size(); i++) 
        {
            // 如果新进来的 nums[i] 大于等于滑动窗口的尾部元素，
            // 说明该尾部元素肯定不会是任何滑动窗口的最大元素。
            // 而且是循环淘汰掉所有小于等于(<=)新元素的尾部元素。
            while (!Myqueue.empty() && nums[i] >= nums[Myqueue.back()])
                Myqueue.pop_back();

            // 虽然 Myqueue 的头部是最大的元素的索引，但是如果当前滑动窗口已不包括该索引，那么需要弹出
            // Myqueue中存储的是索引，方便判断当前front最大值索引与当前i之间是否超过窗口距离，update
            if (!Myqueue.empty() && i - Myqueue.front() >= k) 
                Myqueue.pop_front();

            Myqueue.push_back(i);

            //i达到k-1之后，每一轮窗口都要push进去一个max值
            if (i >= k-1) 
                result.push_back(nums[Myqueue.front()]);
        }
        return result;
    }
};
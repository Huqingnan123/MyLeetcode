class Solution {
public:
    // 1、 默认是大顶堆，队列中元素降序排列，大的元素在队首，优先出队
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> q;
        for(auto num : nums)
            q.push(num);
        for(int i = 1; i < k; i++)
            q.pop();
        return q.top();

    }

    // 2、快速选择，分治partition
    // int findKthLargest(vector<int>& nums, int k) {
    //     // 对区间[begin,end)进行partition
    //     int begin = 0, end = nums.size();
    //     while(begin < end)
    //     {
    //         int pos = partition(nums, begin, end);
    //         if(pos == nums.size() - k)
    //             return nums[pos];
    //         else if(pos < nums.size() - k)
    //             begin = pos + 1;
    //         else
    //             end = pos;
    //     }
    //     return 0;
    // }
    //
    // 利用partition进行双指针快速选择划分区间，返回pivot枢纽位置(quicksort的重要partition)
    // int partition(vector<int>& nums, int begin, int end) {
    //     int pivot = nums[begin];
    //     while(begin < end)
    //     {
    //         while(begin < end && nums[--end] >= pivot);
    //         nums[begin] = nums[end];
    //         while(begin < end && nums[++begin] <= pivot);
    //         nums[end] = nums[begin];
    //     }
    //     nums[begin] = pivot;
    //     return begin;
    // }
};
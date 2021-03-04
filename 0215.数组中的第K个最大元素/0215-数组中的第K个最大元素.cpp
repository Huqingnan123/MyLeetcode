class Solution {
public:
    // 1�� Ĭ���Ǵ󶥶ѣ�������Ԫ�ؽ������У����Ԫ���ڶ��ף����ȳ���
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> q;
        for(auto num : nums)
            q.push(num);
        for(int i = 1; i < k; i++)
            q.pop();
        return q.top();

    }

    // 2������ѡ�񣬷���partition
    // int findKthLargest(vector<int>& nums, int k) {
    //     // ������[begin,end)����partition
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
    // ����partition����˫ָ�����ѡ�񻮷����䣬����pivot��Ŧλ��(quicksort����Ҫpartition)
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
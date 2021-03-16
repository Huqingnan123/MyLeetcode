class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        //从第一个非叶子节点开始调整堆（构造大顶堆）
        for(int i = nums.size()/2 - 1; i >= 0; i--) {
            make_heap(nums, i, nums.size()-1);
        }
        //选择max值（即为nums[0]）下沉k次
        for(int i = nums.size()-1; i >= 0; i--) {
            swap(nums[i], nums[0]);
            make_heap(nums, 0, i-1);
        }
        return nums[nums.size()-k];
    }
    //自上而下调整堆
    void make_heap(vector<int>& nums, int begin, int end) {
        int parent = begin;
        int child = begin * 2 + 1;
        while(child <= end) {
            if(child + 1 <= end && nums[child+1] > nums[child])
                child = child + 1;
            if(nums[parent] > nums[child])
                break;
            swap(nums[child], nums[parent]);
            parent = child;
            child = parent * 2 + 1;
        }
    }
};
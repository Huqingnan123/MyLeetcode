class Solution {
public:
    // 1、暴力遍历O(n^2)直接超时

    // 2、利用归并排序的过程计算逆序对的个数
    int count = 0;
    int reversePairs(vector<int>& nums) {
        //声明辅助数组，用于归并排序使用
        vector<int> temp(nums.size());
        mergeSort(nums, 0, nums.size()-1, temp);
        return count;
    }
    void mergeSort(vector<int>& nums, int left, int right, vector<int>& temp) {
        if(right - left < 1)
            return ;
        int mid = left + (right - left)/2;
        mergeSort(nums, left, mid, temp);
        mergeSort(nums, mid+1, right, temp);
        mergeAndCount(nums, left, mid, right, temp);
    }
    void mergeAndCount(vector<int>& nums, int left, int mid, int right, vector<int>& temp) {
        int i = left, j = mid + 1, k = left;
        while(i <= mid || j <= right)
        {
            //第二个区间直接合并进去
            if(i > mid)
                temp[k++] = nums[j++];
            else if(j > right)
                temp[k++] = nums[i++];
            else if(nums[i] <= nums[j])
                temp[k++] = nums[i++];
            else if(nums[i] > nums[j])
            {
                temp[k++] = nums[j++];
                //只有这里才涉及到逆序数对的计算
                count += mid - i + 1;
            }
        }
        //nums两边区间的归并结果，复制进整体nums中
        for(k = left; k <= right; k++)
            nums[k] = temp[k];
    }
};
class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {
        //若要求时间复杂度 O(N)，空间复杂度 O(1)。故不使用sort排序的方法，也不使用额外的标记数组visited
        //将遍历到的num根据其正负得到对应的绝对值非负索引index，将index索引处的值进行取相反数，该位置一定变为非正数
        //以后再遇到某索引index处的数小于0，直接返回index（最后return 0用于解决只有0重复，索引0位置刚好为0的特殊情形)
        int index;
        for(auto num : nums)
        {
            //get the right nonegative index
            index = num > 0 ? num : -num;
            if(nums[index] < 0)
                return index;
            else
                nums[index] = -nums[index];
        }
        return 0;
    }
};
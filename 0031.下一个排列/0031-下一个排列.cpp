class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int index;
        //寻找第一个非逆序排列的元素
        for(index = nums.size() - 1; index > 0; index--)
        {
            if(nums[index-1] < nums[index])
                break;
        }
        //当不存在下一个更大的排列时，重新排列成最小的排列（升序排列）,全部逆序
        if(index == 0)
            reverse(nums.begin(), nums.end());
        //index - 1对应的元素即为第一个非逆序元素，与最后一个大于它的元素互换位置，再reverse之后序列
        else
        {
            int last = nums.size()-1;
            while(nums[last] <= nums[index - 1])
                last--;
            swap(nums[last],nums[index - 1]);
            reverse(nums.begin() + index, nums.end());
        }   
    }
};
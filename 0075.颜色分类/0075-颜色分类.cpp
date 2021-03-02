class Solution {
public:
    // 可以不使用sort库函数，使用常数空间的一趟扫描算法!!!

    // 1、计数，然后重写数组
    // void sortColors(vector<int>& nums) {
    //     int num0 = 0;
    //     int num1 = 0;
    //     for(auto num : nums)
    //     {
    //         if(num == 0)
    //             num0++;
    //         else if(num == 1)
    //             num1++;
    //     }
    //     for(int i = 0 ; i <= nums.size()-1; i++)
    //     {
    //         if(num0 != 0)
    //         {
    //             nums[i] = 0;
    //             num0--;
    //         }
    //         else if(num1 != 0)
    //         {
    //             nums[i] = 1;
    //             num1--;
    //         }
    //         else
    //             nums[i] = 2;
    //     }    
    // }

    // 2、双指针交换，把所有的0移到最前面，把所有的2移到最后面 
    void sortColors(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;
        // 最后交换完成后，left和right之间全是1 (遇到数字1不用操作)
        for (int i = 0; i <= right; i++) {
            if (nums[i] == 0) 
            {
                swap(nums[left], nums[i]);
                left++;
            }
            if (nums[i] == 2) 
            {
                swap(nums[right], nums[i]);
                right--;
                // 挪完 2 如果换出来的不是 1 ，那么指针要回退，因为 0 和 2 都是需要再次移动的（0->前面，2->后面）
                if (nums[i] != 1) 
                    i--;
            }
        }
        return;
    }
};
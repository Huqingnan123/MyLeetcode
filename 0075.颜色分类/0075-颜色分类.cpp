class Solution {
public:
    // ���Բ�ʹ��sort�⺯����ʹ�ó����ռ��һ��ɨ���㷨!!!

    // 1��������Ȼ����д����
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

    // 2��˫ָ�뽻���������е�0�Ƶ���ǰ�棬�����е�2�Ƶ������ 
    void sortColors(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;
        // ��󽻻���ɺ�left��right֮��ȫ��1 (��������1���ò���)
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
                // Ų�� 2 ����������Ĳ��� 1 ����ôָ��Ҫ���ˣ���Ϊ 0 �� 2 ������Ҫ�ٴ��ƶ��ģ�0->ǰ�棬2->���棩
                if (nums[i] != 1) 
                    i--;
            }
        }
        return;
    }
};
class Solution {
public:
    // 1�����ö�������ռ�map
    // int majorityElement(vector<int>& nums) {
    //     unordered_map<int,int> mp;
    //     for(int num : nums)
    //     {
    //         mp[num]++;
    //         if(mp[num] > nums.size()/2)
    //             return num;
    //     }
    //     return 0;
    // }

    // 2������ͶƱ���⣬���� Boyer-Moore Majority Vote Algorithm ��ʹ��ʱ�临�Ӷ�Ϊ O(N)
    int majorityElement(vector<int>& nums) {
        int curNum = nums[0];
        int count = 1;
        // һ�����ڶ���Ԫ�أ�����curNumһ���Ƕ���Ԫ��
        for(int i = 1; i < nums.size(); i++)
        {
            if(nums[i] == curNum)
                count++;
            else
                count--;
            //��count��Ϊ0ʱ����Ҫת�����Ԫ��curNumΪ��ǰԪ��nums[i], count������Ϊ1
            if(count == 0)
            {
                curNum = nums[i];
                count = 1;
            }    
        }
        return curNum;
    }
};
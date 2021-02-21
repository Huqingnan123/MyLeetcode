class Solution {
public:
    // 1、采用额外计数空间map
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

    // 2、多数投票问题，利用 Boyer-Moore Majority Vote Algorithm ，使得时间复杂度为 O(N)
    int majorityElement(vector<int>& nums) {
        int curNum = nums[0];
        int count = 1;
        // 一定存在多数元素，最后的curNum一定是多数元素
        for(int i = 1; i < nums.size(); i++)
        {
            if(nums[i] == curNum)
                count++;
            else
                count--;
            //当count变为0时，需要转变计数元素curNum为当前元素nums[i], count重新置为1
            if(count == 0)
            {
                curNum = nums[i];
                count = 1;
            }    
        }
        return curNum;
    }
};
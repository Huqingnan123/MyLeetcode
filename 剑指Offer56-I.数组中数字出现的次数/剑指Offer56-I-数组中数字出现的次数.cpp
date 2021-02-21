class Solution {
public:
    vector<int> singleNumbers(vector<int>& nums) {
        int mask = 0;
        //最后mask的值就是num1 ^ num2(分别为两个只出现一次的数字)，为1的位置是两数二进制相异的数位
        for(int num : nums)
            mask ^= num;
        //只保留其最右边一位的1（区分出现一次的两个元素，分组再异或）
        mask &= (-mask);      
        vector<int> result(2);
        for(int num : nums)
        {
            //如果最右边一位1和mask的最右边一位1相同, 分至一组
            if(num & mask)
                result[0] ^= num;
            else
                result[1] ^= num;
        }
        return result;
    }
};
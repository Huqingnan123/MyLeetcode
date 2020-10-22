class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int dis_mask = 0;
        for(auto& num : nums)  //k最后为1的位置代表a,b二进制数0，1相异的位置
            dis_mask ^= num;
        dis_mask &= (-dis_mask);      //只保留其最右边一位的1（区分出现一次的两个元素，分组再异或）
        vector<int> result(2,0);
        for(auto& num : nums)
        {
            if(num & dis_mask)        //根据dis_mask将a,b放到两个组分别异或得出
                result[0] ^= num;
            else
                result[1] ^= num;
        }
        return result; 
    }
};
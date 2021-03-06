class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        int count[101] = {0};
        for(auto& num : nums)
            count[num]++;
        //类似于“计数排序”的手段
        for(int i = 1; i < 100; i++)
        {
            count[i] += count[i-1];       //计算小于等于每个数的个数
        }
        for(auto& num : nums)
        {
            if(num == 0)
                num = 0;
            else
                num = count[num-1];
        }
        return nums;
    }
};
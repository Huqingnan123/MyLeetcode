class Solution {
public:
    //双指针即可，up为最长的“最后上升”的摆动序列长度，down为最长的”最后下降”的摆动序列长度
    int wiggleMaxLength(vector<int>& nums) {
        if(nums.size() <= 1)
            return nums.size();
        int up = 1;
        int down = 1;
        for (int i = 1; i < nums.size(); i++) 
        {
            //只要nums[i] > nums[i-1]，摆动序列可以在最长down序列的基础上+1长度
            if (nums[i] > nums[i-1]) 
                up = down + 1;
            //只要nums[i] < nums[i-1]，摆动序列可以在最长up序列的基础上+1长度
            else if (nums[i] < nums[i-1]) 
                down = up + 1;
        }
        return max(up, down);
    }
};
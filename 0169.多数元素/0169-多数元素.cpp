class Solution {
public:
    //方法有很多：哈希，排序和消除（此处采用“消除法”，时间On,空间O1）
    int majorityElement(vector<int>& nums) {
       int cur_num = nums[0];
       int count = 1;
       for(int i = 1; i < nums.size(); i++)
       {
            if (count == 0)        //直接把当前新数作为起始继续消除
            {
                cur_num = nums[i]; 
                count = 1;
            }
            else
            {
                if (nums[i] == cur_num) 
                    count++;
                else 
                    count--;
            }
       }
       //最后留下的数就是出现超过n/2次的数
       return cur_num;
    }
};
class Solution {
public:
   vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());
        int length = nums.size();
        for (int i = 0; i <= length - 4; i++)
        {
            //nums[i]加上最后三个数也不到target，继续下一个nums[i++],continue
            if (nums[i] + nums[length-3] + nums[length-2] + nums[length-1] < target)   
                continue;
            for (int j = i + 1; j <= length - 3; j++)
            {
                //nums[i]加上nums[j]之后三个数都比target大，此时不用再进行寻找，直接结束这一轮j, break跳出更新i
                if (nums[j] + nums[i] + nums[j+1] + nums[j+2] > target)     
                    break;
                int remain_sum = target - nums[j] - nums[i];
                int low = j + 1;
                int high = length - 1;
                while (low < high)
                {
                    int intLow = nums[low];
                    int intHigh = nums[high];
                    if (intLow + intHigh == remain_sum)     //找到两个数和为remain_sum
                    {
                        result.emplace_back(vector<int> {nums[i], nums[j], intLow, intHigh});
                        //需要去重，移到另外两个不同的数上
                        while (low < high && nums[low] == intLow)
                            low++;
                        while (low < high && nums[high] == intHigh)
                            high--;
                    }
                    else if (intLow + intHigh > remain_sum)
                        high--;
                    else
                        low++;
                }
                //跳过相同的nums[j]值
                while (j+1 <= length - 3 && nums[j] == nums[j+1])
                    j++;
            }
            //跳过相同的nums[i]值
            while (i+1 <= length - 4 && nums[i] == nums[i+1])
                i++;
        }
        return result;
    }
};
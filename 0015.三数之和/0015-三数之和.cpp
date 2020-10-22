class Solution {
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        vector<vector<int>> result;
        vector<int> temp_Vec;
        int vecSize = int(nums.size());
        if (vecSize <= 2)
        {
            return result;
        }
        int possibleSize = vecSize - 2; //第一个数最多循环到倒数第三个数，只有vecSize-2个数可作为起始
        sort(nums.begin(), nums.end()); //先排序（从小到大）

        for (int index = 0; index < possibleSize; index++)    
        {
            int intNow = nums[index];
            if(intNow > 0){
                break;
            }
            int negativeNow = 0 - intNow;
            int low = index + 1;      //当前index所指处右边的第一个数
            int high = vecSize - 1;   //nums最右边的一个数
            while (low < high)        //循环条件
            {
                int intLow = nums[low];
                int intHigh = nums[high];

                if (intLow + intHigh == negativeNow)
                {
                    temp_Vec = {intNow, intLow, intHigh};
                    result.push_back(temp_Vec);
                    //去重
                    while (low < high && nums[low] == intLow)    //一直右移直到一个不同的数
                    {
                        low++;
                    }
                    while (low < high && nums[high] == intHigh)         //一直左移直到一个不同的数
                    {
                        high--;
                    }
                }
                else if (intLow + intHigh < negativeNow)
                {
                    low++;
                }
                else if (intLow + intHigh > negativeNow)
                {
                    high--;
                }
            }
            //去重
            while (index + 1 < possibleSize && nums[index] == nums[index + 1])
            {
                index++;
            }
        }
        return result;
    }
};
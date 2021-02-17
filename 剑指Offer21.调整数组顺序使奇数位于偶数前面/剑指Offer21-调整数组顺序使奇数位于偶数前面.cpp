class Solution {
public:
    vector<int> exchange(vector<int>& nums) {
        int oddCount = 0;
        for(auto num : nums)
            if(num % 2 == 1)
                oddCount++;
        //0 ~ oddCount-1索引放置所有偶数，oddCount ~ nums.size()-1索引放置所有奇数
        int i = 0, j = oddCount;
        vector<int> result(nums.size());
        for(auto num : nums)
        {
            if(num % 2 == 1)
                result[i++] = num;
            else
                result[j++] = num;
        }
        return result;
    }
};
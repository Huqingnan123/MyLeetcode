class Solution {
public:
    vector<int> exchange(vector<int>& nums) {
        int oddCount = 0;
        for(auto num : nums)
            if(num % 2 == 1)
                oddCount++;
        //0 ~ oddCount-1������������ż����oddCount ~ nums.size()-1����������������
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
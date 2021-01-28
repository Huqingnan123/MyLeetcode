class Solution {
public:
    //采用前缀和的思想，要找到一个子数组[j,i]的和为K，只要前缀和之差pre[i] - pre[j-1] == K
    //采用hash表记录“前缀和为key的[0,i]子数组的个数value”，采用pre记录[0,curretIndex]的区间前缀和
    //一次遍历，不断更新前缀和preSum以及hash表，count加上hash[preSum-K]的值(就是[j,current_i]子数组的个数)
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> hash;
        hash[0] = 1;
        int count = 0;
        int preSum = 0;
        for (auto& num : nums) {
            preSum += num;
            if (hash.find(preSum - k) != hash.end()) {
                count += hash[preSum - k];
            }
            hash[preSum]++;
        }
        return count;
    }
};
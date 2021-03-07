class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        // k == 0 需要至少连续两个0
        if(k == 0) {
            for(int i = 0; i < nums.size() - 1; i++)
                if(nums[i] == 0 && nums[i+1] == 0)
                    return true;
            return false;
        }
        // key是preSum % k, value是该preSum的索引i
        unordered_map<int, int> hash;
        hash[0] = -1;
        int preSum = 0;
        int module = 0;
        for(int i = 0; i < nums.size(); i++) {
            preSum += nums[i];
            module = preSum % k;
            // 连续子数组至少包含两个数
            if(hash.find(module) != hash.end() && i - hash[module] >= 2)
                return true;
            //保持hash(module)索引值最小化
            else if(hash.find(module) == hash.end())
                hash[module] = i;
        }
        return false;
    }
};
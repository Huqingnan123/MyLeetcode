class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        // k == 0 ��Ҫ������������0
        if(k == 0) {
            for(int i = 0; i < nums.size() - 1; i++)
                if(nums[i] == 0 && nums[i+1] == 0)
                    return true;
            return false;
        }
        // key��preSum % k, value�Ǹ�preSum������i
        unordered_map<int, int> hash;
        hash[0] = -1;
        int preSum = 0;
        int module = 0;
        for(int i = 0; i < nums.size(); i++) {
            preSum += nums[i];
            module = preSum % k;
            // �������������ٰ���������
            if(hash.find(module) != hash.end() && i - hash[module] >= 2)
                return true;
            //����hash(module)����ֵ��С��
            else if(hash.find(module) == hash.end())
                hash[module] = i;
        }
        return false;
    }
};
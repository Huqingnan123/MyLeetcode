class Solution {
public:
    //����ǰ׺�͵�˼�룬Ҫ�ҵ�һ��������[j,i]�ĺ�ΪK��ֻҪǰ׺��֮��pre[i] - pre[j-1] == K
    //����hash���¼��ǰ׺��Ϊkey��[0,i]������ĸ���value��������pre��¼[0,curretIndex]������ǰ׺��
    //һ�α��������ϸ���ǰ׺��preSum�Լ�hash��count����hash[preSum-K]��ֵ(����[j,current_i]������ĸ���)
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
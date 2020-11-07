class Solution {
public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        int size = nums.size();
        multiset<long long> preSum_set; // �������ǰ׺�ͣ����ܶ����ظ�ֵ��ѡ��multiset���Զ�����)

        long long preSum = 0;
        long long result = 0;
        for (int i = 0; i < size; i++ ){
            preSum += nums[i];         

            if(preSum >= lower && preSum <= upper )
                result++;
            
            if(preSum_set.size() != 0){
                //����multiset��sum�ĸ�����ʹ��lower <= presum - sum <= upper
                //����֮����� presum - upper <= sum <= presum - lower 
                //��ǰǰ׺�� ��ȥ ֮ǰǰ׺�ͣ�ǰ׺��������������Ҫ�󣬾Ϳɵõ�һ�ַ������������
                //��multiset�в��ҷ���Ҫ���sum�ĸ��� 
                auto it1 = preSum_set.lower_bound(preSum - upper);
                auto it2 = preSum_set.upper_bound(preSum - lower);
                result += (std::distance(it1, it2));
            } 
            preSum_set.insert(preSum);
        }
        return result;
    }
};
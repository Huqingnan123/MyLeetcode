class Solution {
public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        int size = nums.size();
        multiset<long long> preSum_set; // 储存各个前缀和，不能丢弃重复值（选用multiset，自动有序)

        long long preSum = 0;
        long long result = 0;
        for (int i = 0; i < size; i++ ){
            preSum += nums[i];         

            if(preSum >= lower && preSum <= upper )
                result++;
            
            if(preSum_set.size() != 0){
                //查找multiset中sum的个数，使得lower <= presum - sum <= upper
                //化简之后就是 presum - upper <= sum <= presum - lower 
                //当前前缀和 减去 之前前缀和，前缀和作差满足上述要求，就可得到一种符合题意的区间
                //在multiset中查找符合要求的sum的个数 
                auto it1 = preSum_set.lower_bound(preSum - upper);
                auto it2 = preSum_set.upper_bound(preSum - lower);
                result += (std::distance(it1, it2));
            } 
            preSum_set.insert(preSum);
        }
        return result;
    }
};
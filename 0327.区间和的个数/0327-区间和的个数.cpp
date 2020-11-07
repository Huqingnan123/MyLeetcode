class Solution {
public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        int size = nums.size();
        multiset<long long> preSum_set; // 储存各个前缀和，不能丢弃重复值（选用multiset，自动有序)

        long long preSum = 0;
        long long result = 0;
        for (int i = 0; i < size; i++ ){
            preSum += nums[i];         //一共size个前缀和

            if(preSum >= lower && preSum <= upper )
                result++;
            
            if(preSum_set.size() != 0){
                long long thresh1 = preSum - upper;
                long long thresh2 = preSum - lower;

                auto it1 = preSum_set.lower_bound(thresh1);
                auto it2 = preSum_set.upper_bound(thresh2);

                result += (std::distance(it1, it2) );
            } 
            preSum_set.insert(preSum);
        }
        return result;
    }
};
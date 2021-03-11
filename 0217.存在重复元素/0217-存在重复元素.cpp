class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int, int> hash;
        for(auto num : nums) {
            hash[num]++;
            if(hash[num] == 2)
                return true;
        }
        return false;
    }
};
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> my_set;
        vector<int> result;
        for(auto& num : nums1)
            my_set.insert(num);
        for(auto& num : nums2)
        {
            if(my_set.find(num) != my_set.end())
            {
                my_set.erase(num);
                result.push_back(num);
            }    
        }
        return result;
    }
};
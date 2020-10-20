#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> vec;
        multimap<int, int> map;    //用map存每个数的下标
        for (int i = 0; i < nums.size(); i++)
        {
            map.insert({ nums[i],i });
            int another = target - nums[i];
            if (another == nums[i] && map.count(another) > 1)
            {
                vec.push_back((map.find(another))->second);
                vec.push_back(i);
                return vec;
            }
            if (another != nums[i] && map.find(another) != map.end())
            {
                vec.push_back((map.find(another))->second);
                vec.push_back(i);
                return vec;
            }
        }
        return vec;
    }
};
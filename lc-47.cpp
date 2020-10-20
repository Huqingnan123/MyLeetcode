#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> permutation_Unique(vector<int>& nums) {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());              //先构成最小字典序的一个排列
        result.emplace_back(nums);
        while (next_permutation(nums.begin(), nums.end())) {   //给出下一个较大字典序排列，直至全部排列被列举完，最后返回FALSE，nums回到原样
            result.emplace_back(nums);
        }
        return result;
    }
};
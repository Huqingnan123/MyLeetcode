#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> permutation_Unique(vector<int>& nums) {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());              //�ȹ�����С�ֵ����һ������
        result.emplace_back(nums);
        while (next_permutation(nums.begin(), nums.end())) {   //������һ���ϴ��ֵ������У�ֱ��ȫ�����б��о��꣬��󷵻�FALSE��nums�ص�ԭ��
            result.emplace_back(nums);
        }
        return result;
    }
};
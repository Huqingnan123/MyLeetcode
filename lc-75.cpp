#include <vector>
using namespace std;
class Solution {
public:
    //方法一：迭代计算出0、1 的个数，然后按照0、1、2的排序，重写当前数组(写完0和1之后，最后全部为2)。
    void sortColors(vector<int>& nums) {
        int num0 = 0;
        int num1 = 0;
        for (auto num : nums)
        {
            if (num == 0)
                num0++;
            else if (num == 1)
                num1++;
        }
        for (int i = 0; i <= nums.size() - 1; i++)
        {
            if (num0 != 0)
            {
                nums[i] = 0;
                num0--;
            }
            else if (num1 != 0)
            {
                nums[i] = 1;
                num1--;
            }
            else
                nums[i] = 2;
        }
    }
};
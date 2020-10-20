#include <vector>
using namespace std;
class Solution {
public:
    //����һ�����������0��1 �ĸ�����Ȼ����0��1��2��������д��ǰ����(д��0��1֮�����ȫ��Ϊ2)��
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
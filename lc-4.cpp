#include <vector>
using namespace std;

//���������������λ����˫ָ����뷨��nums2->nums1��
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int total_number = nums1.size() + nums2.size();
        if (nums1.size() && nums2.size())   //���ǿգ�˫ָ���ƶ���nums2Ԫ��->nums1��
        {
            auto ptr1 = nums1.begin();
            auto ptr2 = nums2.begin();
            while (ptr2 != nums2.end() && ptr1 != nums1.end())
            {
                if (*ptr2 <= *ptr1)
                {
                    ptr1 = nums1.insert(ptr1, *ptr2) + 1;
                    ptr2++;
                }
                else
                    ptr1++;
            }
            if (nums1.size() != total_number)         //�˳�while֮�������δ�ϲ��꣬˵��nums2����Ķ���nums1�е�Ԫ�ش�ֱ�Ӳ���β��
                while (ptr2 != nums2.end())
                {
                    nums1.emplace_back(*ptr2);
                    ptr2++;
                }
            if (total_number % 2 == 0)
                return ((double)nums1[total_number / 2 - 1] + (double)nums1[total_number / 2]) / 2;
            else
                return (double)nums1[total_number / 2];
        }
        else if (!nums1.size())      //nums1��
        {
            if (total_number % 2 == 0)
                return ((double)nums2[total_number / 2 - 1] + (double)nums2[total_number / 2]) / 2;
            else
                return (double)nums2[total_number / 2];
        }
        else if (!nums2.size())      //nums2��
        {
            if (total_number % 2 == 0)
                return ((double)nums1[total_number / 2 - 1] + (double)nums1[total_number / 2]) / 2;
            else
                return (double)nums1[total_number / 2];
        }
        else
            return 0;
    }
};
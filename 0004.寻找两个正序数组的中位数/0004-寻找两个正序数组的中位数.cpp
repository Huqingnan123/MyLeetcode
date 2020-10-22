class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int total_number = nums1.size() + nums2.size();
        auto ptr1 = nums1.begin();
        auto ptr2 = nums2.begin();
        //将nums2中的元素按大小排序插入nums1中
        while(ptr2 != nums2.end() && ptr1 != nums1.end())
        {
            if(*ptr2 <= *ptr1)
            {
                ptr1 = ++nums1.insert(ptr1,*ptr2);
                ptr2++;
            }
            else  
                ptr1++;
        }
        //nums2到底，结束插入
        //nums1到底，nums2直接加在末尾
        if(ptr1 == nums1.end())
        {
            while(ptr2 != nums2.end())
            {
                nums1.emplace_back(*ptr2);
                ptr2++;
            }
        }    
        if(total_number%2 == 0)
            return ((double)nums1[total_number/2-1] + (double)nums1[total_number/2]) / 2;
        else
            return (double)nums1[total_number/2];
    }
};
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        //双指针都“从后往前”遍历，默认选取较大元素置于末尾，防止覆盖nums1前面的元素
        int Index1 = m-1;
        int Index2 = n-1;
        int curIndex = m+n-1;
        //一共遍历m+n次，放完所有元素即可
        while(Index1 >= 0 || Index2 >= 0)
        {
            if(Index1 < 0)
                nums1[curIndex--] = nums2[Index2--];
            else if(Index2 < 0)
                nums1[curIndex--] = nums1[Index1--];
            else if(nums2[Index2] > nums1[Index1])
                nums1[curIndex--] = nums2[Index2--];
            else
                nums1[curIndex--] = nums1[Index1--];
        }
    }
};
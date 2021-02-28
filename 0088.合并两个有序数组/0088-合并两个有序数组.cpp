class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        //˫ָ�붼���Ӻ���ǰ��������Ĭ��ѡȡ�ϴ�Ԫ������ĩβ����ֹ����nums1ǰ���Ԫ��
        int Index1 = m-1;
        int Index2 = n-1;
        int curIndex = m+n-1;
        //һ������m+n�Σ���������Ԫ�ؼ���
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
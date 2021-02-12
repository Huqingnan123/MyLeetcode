class Solution {
public:
    // 1������������������
    // int search(vector<int>& nums, int target) {
    //     int count = 0;
    //     for(int i = 0; i < nums.size(); i++)
    //         if(nums[i] == target)
    //             count++;
    //     return count;
    // }

    // 2�����ַ��Ż�
    // ֻҪ���ҳ����������� k �����������һ��λ�ú����һ��λ�ã�����֪�������ֳ��ֵĴ�����
    int search(vector<int>& nums, int target) {
        return getright(nums, target) - getleft(nums, target) + 1;
    }
    // �����ҵ�һ��λ�ã���߽磩
    int getleft(vector<int>& nums, int target)
    {
        // �ұ߽��ʱ��������ҿ����䣬[2,3,5,7]ʱӦ����[0,4)
        int left = 0, right = nums.size();
        while(left < right)
        {
            int mid = (right + left)/2;
            if(nums[mid] >= target) 
                right = mid;
            else if(nums[mid] < target) 
                left = mid + 1;
        }
        return left;
    }
    // ���������һ��λ�ã��ұ߽磩
    int getright(vector<int>& nums, int target)
    {
        int left = 0, right = nums.size();
        while(left < right)
        {
            int mid = (right + left)/2;
            if(nums[mid] <= target) 
                left = mid + 1;
            else if(nums[mid] > target) 
                right = mid;
        }
        return left - 1;
    }
};
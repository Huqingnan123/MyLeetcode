class Solution {
public:
    // �������⣬������԰������¹��򻮷�Ϊ�����֡�
    // �������飺 nums[i] = i��
    // �������飺 nums[i] != i; 
    // ȱʧ�����ֵ��� �������������λԪ�ء� ��Ӧ����������˿���ʹ�ö��ַ����� �������������λԪ�ء�
    int missingNumber(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;
        while(left <= right)
        {
            int mid = left + (right - left) / 2;
            //ȱ�ٵ�һ�����ұ�����
            if(nums[mid] == mid)
                left = mid + 1;
            //ȱ�ٵ�һ�����������
            else
                right = mid - 1;
        }
        return left;
    }
};
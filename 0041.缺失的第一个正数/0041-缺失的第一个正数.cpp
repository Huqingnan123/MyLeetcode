class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        // ����[1,n]��Χ�ڵ����û���n+1
        for(int i = 0; i < n; i++) {
            if(nums[i] <= 0 || nums[i] > n) {
                nums[i] = n+1;
            }
        }
        //���������г��ֹ���λ��[1,n]֮���pos��������pos-1����nums[pos-1]���Ϊ����������������pos���ֹ���
        for(int i = 0; i < n; i++) {
            int pos = abs(nums[i]);
            if(pos >= 1 && pos <= n) {
                if(nums[pos-1] > 0)
                    nums[pos-1] = -nums[pos-1];
            }
        }
        for(int i = 0; i < n; i++) {
            // nums[i] > 0��ʾ pos:i+1 ��δ���ֹ�������pos-1����nums[i]��δ�����Ϊ����
            if(nums[i] > 0)
                return i+1;
        }
        return n+1;
    }
};
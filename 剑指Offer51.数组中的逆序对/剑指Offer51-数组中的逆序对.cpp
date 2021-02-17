class Solution {
public:
    // 1����������O(n^2)ֱ�ӳ�ʱ

    // 2�����ù鲢����Ĺ��̼�������Եĸ���
    int count = 0;
    int reversePairs(vector<int>& nums) {
        //�����������飬���ڹ鲢����ʹ��
        vector<int> temp(nums.size());
        mergeSort(nums, 0, nums.size()-1, temp);
        return count;
    }
    void mergeSort(vector<int>& nums, int left, int right, vector<int>& temp) {
        if(right - left < 1)
            return ;
        int mid = left + (right - left)/2;
        mergeSort(nums, left, mid, temp);
        mergeSort(nums, mid+1, right, temp);
        mergeAndCount(nums, left, mid, right, temp);
    }
    void mergeAndCount(vector<int>& nums, int left, int mid, int right, vector<int>& temp) {
        int i = left, j = mid + 1, k = left;
        while(i <= mid || j <= right)
        {
            //�ڶ�������ֱ�Ӻϲ���ȥ
            if(i > mid)
                temp[k++] = nums[j++];
            else if(j > right)
                temp[k++] = nums[i++];
            else if(nums[i] <= nums[j])
                temp[k++] = nums[i++];
            else if(nums[i] > nums[j])
            {
                temp[k++] = nums[j++];
                //ֻ��������漰���������Եļ���
                count += mid - i + 1;
            }
        }
        //nums��������Ĺ鲢��������ƽ�����nums��
        for(k = left; k <= right; k++)
            nums[k] = temp[k];
    }
};
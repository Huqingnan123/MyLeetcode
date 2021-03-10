class Solution {
public:
    int search(vector<int>& nums, int target) {
        if(nums.size() == 0)
            return -1;
        //��ת����ķֽ���
        int index =  findHelper(nums, 0, nums.size()-1);
        if(target <= nums[nums.size()-1]) {
            return binarySearch(nums, index, nums.size()-1, target);
        }
        else {
            return binarySearch(nums, 0, index-1, target);
        }
        return -1;
    }
    //Ѱ��ԭ��������minԪ�ص�index��Ԫ��ֵ������ͬ��
    int findHelper(vector<int>& nums, int left, int right) {
        while(left < right) {
            int mid = left + (right - left) / 2;
            if(nums[mid] > nums[right])
                left = mid + 1;
            else if(nums[mid] < nums[right])
                right = mid;
        }
        return left;
    }

    int binarySearch(vector<int>& nums, int left, int right, int target) {
        while(left <= right) {
            int mid = left + (right - left) / 2;
            if(nums[mid] == target)
                return mid;
            else if(nums[mid] < target)
                left = mid + 1;
            else if(nums[mid] > target)
                right = mid - 1;
        }
        return -1;
    }
};
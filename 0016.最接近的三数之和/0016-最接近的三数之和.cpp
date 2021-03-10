class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int diff = INT_MAX;
        int result = 0;
        for(int i = 0; i < nums.size() - 2; i++) {
            int left = i + 1, right = nums.size()-1;
            while(left < right) {
                int num1 = nums[left];
                int num2 = nums[right];
                //�����֦
                if(num1 + num2 + nums[i] == target)
                    return target;
                //���ӽ�targetʱ��������
                if(abs(num1 + num2 + nums[i] - target) < diff) {
                    diff = abs(num1 + num2 + nums[i] - target);
                    result = num1 + num2 + nums[i];
                }
                //ȥ��
                if(num1 + num2 + nums[i] < target) {
                    while(left < right && nums[left] == num1)
                        left++;
                }
                //ȥ��
                else if(num1 + num2 + nums[i] > target) {
                    while(left < right && nums[right] == num2)
                        right--;
                }
            }
            //ȥ��
            while(i + 1 < nums.size() && nums[i+1] == nums[i])
                i++;
        }
        return result;
    }
};
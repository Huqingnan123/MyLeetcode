class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int index = 0;
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] != val) {
                swap(nums[index], nums[i]);
                index++;
            }
        }
        return index;
    }
};
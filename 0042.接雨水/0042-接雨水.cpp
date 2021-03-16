class Solution {
public:
    int trap(vector<int>& height) {
        if(height.size() <= 2)
            return 0;
        int left = 0, right = height.size()-1;
        int leftMax = 0, rightMax = 0;
        int result = 0;
        while(left < right) {
            if(height[left] <= height[right]) {
                leftMax = max(leftMax, height[left]);
                result += leftMax - height[left];
                left++;
            }
            else if(height[right] < height[left]) {
                rightMax = max(rightMax, height[right]);
                result += rightMax - height[right];
                right--;
            }
        }
        return result;
    }
};
class Solution {
public:
    int maxArea(vector<int>& height) {
        if(height.size() <= 1)
            return 0;
        int result = 0;
        int left = 0, right = height.size()-1;
        // 双指针移动，总是移动指向较小元素的指针(正确性可以证明)
        while(left < right) {
            int area = min(height[left], height[right]) * (right - left);
            result = max(result, area);
            if(height[left] <= height[right])
                left++;
            else
                right--;
        }
        return result;
    }
};
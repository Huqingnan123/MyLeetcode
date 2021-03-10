class Solution {
public:
    int maxArea(vector<int>& height) {
        if(height.size() <= 1)
            return 0;
        int result = 0;
        int left = 0, right = height.size()-1;
        // ˫ָ���ƶ��������ƶ�ָ���СԪ�ص�ָ��(��ȷ�Կ���֤��)
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
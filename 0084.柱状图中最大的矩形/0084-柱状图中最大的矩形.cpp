class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> left(n, -1), right(n, n);
        
        stack<int> mono_St;
        for (int i = 0; i < n; ++i) {
            while (!mono_St.empty() && heights[mono_St.top()] >= heights[i]) {
                right[mono_St.top()] = i;
                mono_St.pop();
            }
            if(!mono_St.empty()) {
                left[i] = mono_St.top();
            }
            mono_St.push(i);
        }
        
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            ans = max(ans, (right[i] - left[i] - 1) * heights[i]);
        }
        return ans;
    }
};